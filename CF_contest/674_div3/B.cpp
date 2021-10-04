#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, h;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> a[n];
		for(int i=0; i<n; i++) {
			for(int ix=0; ix<4; ix++) {
				scanf("%d", &h);
				a[i].push_back(h);
			} 
		}
		bool p=false,q=false;
		if(m%2!=0){
			printf("NO\n");
			continue;
		}
		for(int i=0; i<n; i++){
			for(int ix=0; ix<n; ix++){
				if(a[ix][1]==a[i][2] && a[ix][0]==a[i][0] && a[ix][3]==a[i][3]) p=true;
			}
			if(a[i][1]==a[i][2]) q=true;
		}
		if(p && q) printf("YES\n");
		else printf("NO\n");
	}
}