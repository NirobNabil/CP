#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		for(int i=n-1; i>=0; i--) {
			for(int ix=min(a[i],n-1); ix>1; ix--) {
				if(i+ix<n) a[i+ix]--;
				// a[i]--;
			} 
			// for(int i=0; i<n; i++) printf("%+d ", a[i]);
			// printf("\n");
		} 
		// printf("d\n");
		for(int i=1; i<n; i++) {
			if(a[i]<=0) {
				a[i+1] += a[i]-1;
				a[i] = 0;
				// for(int i=0; i<n; i++) printf("%+d ", a[i]);
				// printf("\n");
			}
		}
		ll p = 0;
		for(int i=0; i<n; i++) p += max(a[i]-1, 0);
		printf("%lld\n", p); 
	}
}

// +1 +4 +2 +2 +2 +2 +2
// +1 +4 +2 +2 +2 +2 +1
// +1 +4 +2 +2 +2 +1 +0
// +1 +4 +2 +2 +1 +0 +0
// +1 +4 +2 +1 +0 +0 +0
// +1 +4 +1 +0 -1 -1 +0
// +1 +3 +1 +0 -1 -1 +0
// +1 +3 +1 +0 +0 -2 +0
// +1 +3 +1 +0 +0 +0 -2

