#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int x,y;
	scanf("%d %d", &x, &y);
	string s;
	cin >> s;
	int g = s.length();
	unordered_map<char, int> gg;
	gg['U']=0; gg['D']=0; gg['L']=0; gg['R']=0; 
	for(int i=0; i<g; i++) {
		gg[s[i]]++;
	}
	printf("%d %d\n", x+gg['R']-gg['L'],y+gg['U']-gg['D']);
}