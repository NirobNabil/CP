#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

unordered_map<char, int> j;
vector<pair<int, char> > g;


bool pair_check(char x, char y){
  return (x+y==153 || x+y==158)?true:false;
}

bool axis_check2(char x, char y) {
  return (x+y==153)?true:false; //true=v false=h
}

bool axis_check(char x){
  return (x==68 || x==85)?true:false;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		char a[n];
		scanf("%s", a);
    j['U']=j['D']=j['L']=j['R']=0;
		for(int i=0; i<n; i++) {
			j[a[i]]++;
		}
    for(auto i:j) g.push_back(make_pair(i.second, i.first));
    sort(g.begin(),g.end());
    reverse(g.begin(), g.end());
    if(pair_check(g[0].Y, g[1].Y)){
    	int gg = max(g[0],g[1])/g[2];
    	while((g[0].X>g[1].X?g[1].X:g[0].X)>gg) printf("%c", (g[0].X>g[1].X?g[1].Y:g[0].Y));
    	printf("%c", g[2].Y);
    	while((g[0].X>g[1].X?g[1].X:g[0].X)>max(g[0],g[1])/g[2]) printf("%c", (g[0].X>g[1].X?g[1].Y:g[0].Y));
    }
	}
}