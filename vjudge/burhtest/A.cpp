#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

int main(){
	int t, n, x, m;
	int a[100009];
	map<int, set<int> > b;
	scanf("%d", &t);
	while(t--){
		m=0;
		b.clear();
		scanf("%d %d", &n, &x);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=1; i<=n; i++) {
			a[i] += a[i-1];
		}
		for(int i=1; i<=n; i++) {
			a[i] %= x;
		}
		for(int i=1; i<=n; i++) {
			b[a[i]].insert(i);
		}
		b[0].insert(0);
		// for(auto i:b) {
		// 	printf("%d - ", i.X);
		// 	for(auto ix:i.Y) printf("%d ", ix);
		// 	printf("\n");
		// }
		// for(int i=n; i>=1; i--) {
		// 	for(int ix=0; ix<=i; ix++) {
		// 		if(b[a[i]].find(ix)==b[a[i]].end()) {
		// 			m = max(i-ix, m);
		// 			break;
		// 		}
		// 	}
		// } 
		for(auto i:b) {
			int lmin=0, lmax=n;
			for(auto ix:i.Y) {
				if(ix==lmin) lmin++;
				else if(lmin!=0){
					m = max(lmax-lmin, m);
					break;
				}
			}
			if(lmin==0) {
				m = max(*i.Y.rbegin(), m);
			}
		}
		if(m<=0) printf("-1\n");
		else printf("%d\n", m);
	}
}