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
	ll i, ix, t, n, a, b;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a*b);
	}
}