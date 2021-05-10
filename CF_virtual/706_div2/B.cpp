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
#define CEIL(a,b) ((a)%(b) ? (a)/(b) +1 : (a)/(b))

int main(){
	ll i, ix, t, n, k, x;
	scanf("%lld", &t);
	while(t--){
		std::vector<ll> v;
		scanf("%lld %lld", &n, &k);
		rep(i, 0, n) scanf("%lld", &x), v.pb(x);
		sort(v.A(), v.B());
    v.resize(unique(v.A(), v.B()) - v.A());
		ll mex = -1, mx=0;
		for(int i=0; i<v.size(); i++) {
			if(v[i] > i && mex==-1) mex = i;
			mx = max(mx, v[i]);
		}
		if(mex==-1) mex = mx+1;
		// printf("%d %d\n", mex, mx);

		if( k == 0 ) 
			printf("%u\n", v.size()); 
		else if( mex == mx+1) 			
			printf("%u\n", v.size() + (unsigned long)k);
		else if(mx >= mex+1) 
			printf("%u\n", binary_search(v.A(), v.B(), CEIL(mx+mex, 2)) ? v.size() : v.size()+(unsigned long)1);
	}
	return 0;
}