#include "bits/stdc++.h"
using namespace std;
#define ll long long int

unordered_map<char, int> j;
vector<char> ans;
int x, zz;
bool xx;
char q[4] = {'U','R','D','L'};
char q2[4] = {'U','L','D','R'};

void gg(char a, char b, char c, char d){
	x = min(j[c],j[d]);
	char z = (j[a]==0) ? b : a;
	j[c] -= min(x,j[z]);
	j[d] -= min(x,j[z]);
	char p;
	if(min(x,j[z])%2==0) p = (j[c]<j[d])?d:c;
	else p = (j[c]<j[d])?c:d;
	d = (p==d)?c:d;
	if(d=='R') xx=true;
	for(int i=0; i<min(x,j[z]); i++) {
		// printf("%c%c%c", c,z,d);
		ans.push_back((i%2==0)?p:d);
		ans.push_back(z);
		ans.push_back((i%2==0)?d:p);
	} 
	j[z] -= min(x,j[z]);
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		xx=false;
		ans.clear();
		j.clear();
		int n;
		scanf("%d", &n);
		char a[n];
		scanf("%s", a);
		for(int i=0; i<n; i++) {
			j[a[i]]++;
		}
		x = min(j['U'],min(j['D'],min(j['L'],j['R'])));
		for(int i=0; i<4; i++) j[q[i]] -= x;
		for(int i=0; i<x; i++) {
			ans.push_back('Q');
			// for(int ix=0; ix<4; ix++) ans.push_back(q[ix]); //printf("%c", q[ix]);;
		}
		// printf("%d\n", x);
		// for(auto i:j) printf("%c %d\n", i.first, i.second);
		if( (j['U']!=0 && j['D']==0) || (j['U']==0 && j['D']!=0)) {
			gg('U','D','L','R');
		}else if( (j['R']!=0 && j['L']==0) || (j['R']==0 && j['L']!=0)) {
			gg('L','R','U','D');
		}
		zz=1;
		if((j['U'] && j['D']) || (j['L'] && j['R']) ) printf("Impossible\n"), zz=0;
		if(zz) {
			for(auto i:ans) {
				if(i=='Q'){
					for(int ix=0; ix<4; ix++) printf("%c", (xx)?q2[ix]:q[ix]);
				}else printf("%c", i);
			}
			for(auto i:j) {
				while(i.second--) printf("%c", i.first);
			}
			printf("\n");
		}
		// printf("%d\n", j['U']+j['D']+j['L']+j['R']);
	}
}