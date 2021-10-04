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
	ll i, ix, t, n;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		std::vector<ll> a(2*n);
		for(ll &i: a) {
			scanf("%lld", &i);
		}
		map<ll,ll> occ;
		ll pos = 1;

		for(auto i:a) {
			if(occ[i]>1) pos=0;
			else occ[i]++;
		} 

		sort(a.A(), a.B(), greater<ll>());
		a.resize(unique(a.A(), a.B()) - a.A());

		if( a.size() != n ) pos = 0;
		else {
			ll tm = 0;
			for(int i=0; i<n; i++) {
				if( (a[i]-tm) <= 0 || (a[i]-tm) % (2*(n-i)) != 0 ) {
					pos = 0;
					break;
				}else {
					tm += ( (a[i]-tm) / (2*(n-i)) )*2;
				}
			}
		}
		if(pos) printf("YES\n");
		else printf("NO\n");
	}
}