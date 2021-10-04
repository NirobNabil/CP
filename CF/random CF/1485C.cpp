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
	int i, ix, t, n, x, y, a[S1];
	scanf("%d", &t);
	while(t--){
		ll ans=0;
		scanf("%d %d", &x, &y);
		for(int i=1; (x-i)/i-i > 0 && i<y; i++) {
			ans += min(y-i,(x-i)/i -i);
		} 
		printf("%lld\n", ans);
	}
}