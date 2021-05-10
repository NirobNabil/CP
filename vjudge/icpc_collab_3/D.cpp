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
	int i, ix, t, tc, n;
	scanf("%d", &tc);
	for(int t=1; t<=tc; t++) {
		scanf("%d", &n);
		vector<ll> a;
		rep(i, 0, n) {
			scanf("%d", &ix);
			a.pb(ix);
		}

		sort(a.A(), a.B());
		// y + z = x + c*z
		// y - x = (c-1)*z
		ll x = 0, y, ny, z=1, c;
		// for(int i=0; i<n; i++) printf("%lld ", a[i]);
		// 	printf("\n");
		while(a[0] >= x) {
			y = a[0];
			auto it = upper_bound(a.A(), a.B(), a[0]);
			if(it != a.end()) ny = *it;
			else ny = INT_MAX;
			c = 1;
			for(int i=0; i<n-1 && a[i]==a[i+1]; i++) c++; 

			if(c == 1) {
				z = ny - y;
			}else if( (ny-y) < (y-x)/max((ll)1,(c-1)) ) {
				z = ny - y;
			}else z = min(ny, (y-x)/max((ll)1,(c-1)));

			if(z==0) {
				x += y-x;
				break;
			}
			for(int i=0; i<c; i++) a[i] += z;

			x += z*c;
		}
		printf("Case #%d: %d\n", t, x+1);
	}
}