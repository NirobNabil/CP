#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ll i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%lld", &t);
	while(t--){
		int a, b;
		ll ans = 0;
		scanf("%lld %d %d", &n, &a, &b);
		if(2*a > b) {
			ans += (n / 2) * b;
			if(n%2 == 1) ans += a;
		}else {
			ans += n*a;
		}
		printf("%lld\n", ans);
	}
}