#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, t, a_min=INT_MAX, b_min=INT_MAX;
		vector<int> a, b;
		scanf("%d", &n);
		int c[n];
		for(int i=0; i<n; i++) scanf("%d", &t), a.push_back(t), a_min=min(a_min,t);
		for(int i=0; i<n; i++) scanf("%d", &t), b.push_back(t), b_min=min(b_min,t);
		for(int i=0; i<n; i++) {
			c[i] = max(a[i]-a_min, b[i]-b_min);
		}
		ll res=0;
		for(int i=0; i<n; i++) res+=c[i];
		printf("%lld\n", res);
	}
}