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

map<ll, ll> occ, arr, occ2;

int main(){
	ll i, ix, t, n, a[S1];
	scanf("%lld", &t);
	while(t--){
		occ.clear();
		occ2.clear();
		ll amax=0, amin=LONG_MAX;
		scanf("%lld", &n);
		rep(i, 0, n) scanf("%lld", &ix), occ[ix]++;
		for(auto i:occ) occ2[i.Y]++;
		for(auto i:occ2) {
			amax = max(i.X, amax);
			amin = min(i.X, amin);
		}

		std::vector<ll> cost_r(amax+9), cost_l(amax+9);;
		for(int i=amax, x=0; i>=amin; i--) {
			if(occ2[i+1]) x += occ2[i+1];
			cost_r[i] = cost_r[i+1] + x;
		}

		for(int i=amin; i<amax; i++) {
			cost_l[i] = cost_l[i-1] + occ2[i]*i;
		}


		ll cost = LONG_MAX;
		for(int i=amin; i<=amax; i++) {
			cost = min(cost, cost_r[i]+cost_l[i-1]);
		}
		printf("%lld\n", cost);
	}
}