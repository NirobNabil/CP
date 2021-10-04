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

ll bpow(ll a, ll b, ll m) {
    a %= m;
    ll r = 1;
    while( b>0 ) {
        if(b & 1) r = (r * a) % m;
        a = (a * a)%m;
        b >>= 1;
    }
    return r;
}


ll bdiv(ll a, ll b, ll m) {
    // https://www.geeksforgeeks.org/fermats-little-theorem/
    return (a%m) * bpow(b, m-2, m) % m;
}


ll bfact(ll a, ll m) {
    ll ans = 1;
    for(int i=1; i<=a; i++) {
        ans = (ans * i) % m;
    }
    return ans;
}


ll ncr(ll n, ll r, ll m) {
    return bdiv(bfact(n, m), (bfact(r, m) * bfact(n-r, m)) % m, m);
}

int main(){
	int k, i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		rep(i, 0, n) scanf("%d", &a[i]);
		a[n] = INT_MIN;
		sort(a, a+n, greater<int>());
		ll cn, cr, lc=0;
		for(int i=1; i<=n; i++) {
			if(a[i] != a[i-1]) {
				if(i >= k) {
					cn = i - lc;
					cr = k - lc;
					// printf("- %d %d %d %d\n", lc, i, cn, cr);
					break;
				}
				lc=i;
			}
		}
		
		printf("%lld\n", ncr(cn, cr, 1000000007));
	}
}