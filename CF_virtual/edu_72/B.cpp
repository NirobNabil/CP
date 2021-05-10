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

vector<ll> v;

int main(){
	ll t;
	scanf("%lld", &t);	
	ll sum = 0, i=1;
	do {
		v.pb(sum);
		// printf("%lld %lld\n", i, sum);
		sum += (i++);
	} while( sum < 10e10 );
	ll x = 100;
	// for(int i=0; i<x; i++) printf("%lld\n", v[i]);;
	// printf("\n");

	while(t--){
		ll a, b;
		cin >> a >> b;
		bool pos = false;
		// cout << v.size() <<endl;
		auto it=lower_bound(v.A(), v.B(), max(a,b)-min(a,b));
		for(; it!=v.end(); it++) {
			if((*it + a+b)%2 == 0) break;
		}
		printf("%d\n", it-v.begin());
	}
}