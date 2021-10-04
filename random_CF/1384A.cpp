#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n+5];
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		a[n] = a[n-1];
		vector<char> tp[120];
		int s, l;
		for(int i=0; i<=n; i++) {
			if(i==0){
				if(a[i]>0){
					for(int ix=0; ix<a[i]; ix++) tp[i].push_back('a');
				} else tp[i].push_back('a');
				l=max(a[i],1);
				s=a[i];
			}else {
				int ix=0;
				for(; ix<s; ix++) tp[i].push_back(tp[i-1][ix]);
				for(; ix<a[i]; ix++) {
					if(ix<l) {
						tp[i].push_back((tp[i-1][ix]+1<'z')?tp[i-1][ix]+1 : tp[i-1][ix]-1);
					}else tp[i].push_back((tp[i].size()>0)?tp[i][ix-1]:'a');
				}
				if(s==0 && a[i]==0) {
					tp[i].push_back((tp[i-1][0]+1<'z')?tp[i-1][0]+1 : tp[i-1][0]-1);
				}
				l = max(a[i],s);
				s = a[i];
			}
		}

		for(int i=0; i<=n; i++) {
			for(auto ix:tp[i]) printf("%c", ix);
			printf("\n");
		}
	}
}