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
	ll i, ix, t, n, nx, ny, x, y;
	scanf("%lld %lld", &nx, &ny);
	scanf("%lld", &n);
	map<ll, set<ll> > coos;
	ll ys = 0;
	rep(i, 0, n) {
		scanf("%lld %lld", &x, &y);
		coos[x].insert(y);
	}
	for(auto i:coos) {
		ys += 
				i.Y.begin() 
			+ (*i.Y.size()>1 ? *i.Y.rbegin() : 0);
	}
	ll road = CEIL(ys, n);
	ll cost = 0;
	for(auto i:coos) {
		cost += 
				(*i.Y.begin()<road ? llabs(road - *i.Y.begin()) : 0) 
			+ (*i.Y.rbegin()>road ? llabs(road - *i.Y.rbegin()) : 0);
	}
	road = ys/n;
	ll cost2 = 0;
	for(auto i:coos) {
		cost2 += 
				(*i.Y.begin()<road ? llabs(road - *i.Y.begin()) : 0) 
			+ (*i.Y.rbegin()>road ? llabs(road - *i.Y.rbegin()) : 0);
	}
	printf("%lld\n", min(cost*2 + nx-1, cost2*2 + nx-1));
}