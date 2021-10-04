#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, h;
		char l;
		scanf("%d %d", &n, &k);
		printf("%d\n", n);
		char v[n];
		scanf("%s", v);
		h=0;
		int r=0;
		for(int i=0; i<n; i++) {
			if(i<k) {
				if(v[i]!='?') r += (v[i]=='0'?-1:1);
				else h++;
			}else {
				if(v[i-k]=='?') h--;
				else r -= (v[i-k]=='0'?-1:1);
				if(v[i]=='?') h++;
				else r += (v[i]=='0'?-1:1);
			}
			if(i>=k-1) {
				if( h<abs(r) || abs(abs(r)-h)%2!=0 ) {
					printf("NO\n");
					h = -1;
					break;
				}
			}
		}
		for(int i=0; i<n && h!=-1; i++) {
			if(i<k*2) {
				if(v[i]!='?') r += (v[i]=='0'?-1:1);
				else h++;
			}else {
				if(v[i-k*2]=='?') h--;
				else r -= (v[i-k*2]=='0'?-1:1);
				if(v[i]=='?') h++;
				else r += (v[i]=='0'?-1:1);
				if( h<abs(r) || abs(abs(r)-h)%2!=0 ) {
					printf("NO\n");
					h = -1;
					break;
				}
			}
			printf("%d %d %d %d\n", n, h, i, r);
			if(i>=min(k*2-1,n-1)) {
				if( h<abs(r) || abs(abs(r)-h)%2!=0 ) {
					printf("NO\n");
					h = -1;
					break;
				}
			}
		}
		if(h!=-1) printf("YES\n");
	}
}