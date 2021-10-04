#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, h;
		std::vector<int> v;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &h), v.push_back(h);
		for(int i=n-1; i>=0; i--) {
			if(v[i]<0) {
				for(int ii=i; ii>=0 && v[i]<0; ii--) {
					if(v[ii]>0) {
						// h = max(v[ii],v[i])-min(v[ii],v[i]);
						// printf("h=%d\n", h);
						if(abs(v[ii])<=abs(v[i])) {
							v[i] += v[ii];
							v[ii] = 0;
							// printf("%d %d\n", v[i], v[ii]);
						} else {
							v[ii] += v[i];
							v[i] = 0;
						}
					}
				} 
			}
		}
		ll r=0;
		for(int i=0; i<n; i++) {
			if(v[i]>=0) r+=v[i];
			else r -= v[i];
		} 
		printf("%lld\n", r/2);
	}
}