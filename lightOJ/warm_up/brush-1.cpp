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
	int i, ix, t, tc, n, a[S1];
	scanf("%d", &t);
	while(tc++<t){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		ll ans = 0;
		for(int i=0; i<n; i++) ans += max(0,a[i]);
		printf("Case %d: %lld\n", tc, ans);
	}
}