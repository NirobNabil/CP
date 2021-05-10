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
#define CEIL(a,b) (a%b?a/b+1:a/b)

ll b[S1];
int main(){
	ll i, ix, t, n, k, a[S1];
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &n, &k);
		rep(i, 0, n) scanf("%lld", &a[i]);
		ll toadd = 0;
		for(int i=1; i<n; i++) {
			b[i] = a[i] + b[i-1];
			// printf("%lld - %lld\n", a[0], b[i-1]);
			toadd += max((ll)0, CEIL(a[i]*100,k) -a[0] -b[i-1]);
			a[0] = max(CEIL(a[i]*100,k) -b[i-1], a[0]);
		}
		printf("%lld\n", toadd);
	}
}