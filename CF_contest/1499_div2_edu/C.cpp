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
#define CEIL(a,b) ( (a)%(b) ? (a)/(b)+1 : (a)/(b) )

int main(){
	int i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		std::vector<ll> a(n);
		rep(i, 0, n) scanf("%lld", &a[i]);
		std::vector<ll> h, v;
		for(int i=0; i<n; i+=2) h.pb(a[i]);
		for(int i=1; i<n; i+=2) v.pb(a[i]);
		std::vector<ll> hmin, vmin;
		for(ll i=0, ch=INT_MAX, cv=INT_MAX; i<CEIL(n, 2); i++) {
			if(i<h.size()) ch = min(ch, h[i]);
			if(i<v.size()) cv = min(cv, v[i]);
			hmin.pb(ch);
			vmin.pb(cv);
		}

		ll ans = 0, ansmin=LONG_MAX;
		// for(auto i:hmin) printf("%d ", i);
		for(int i=0; i<CEIL(n, 2); i++) {
			if(i<h.size()) ans += h[i];
			if(i<v.size()) ans += v[i];
			if(i>0) {
				if(i<h.size()) ans -= hmin[i-1]*(n-i);
				if(i<v.size()) ans -= vmin[i-1]*(n-i);
				// printf("d %lld\n", ans);
			}
			if(i<h.size()) ans += hmin[i]*(n-i-1);
			if(i<v.size()) ans += vmin[i]*(n-i-1);
			// printf("s %lld\n", ans);
			ansmin = min(ansmin, ans);
		}
		printf("%lld\n", ansmin);
	}
}