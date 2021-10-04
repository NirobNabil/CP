#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	ll i, ix, t, x,y,n, ans, q, k, a[S1], b[S1], c[S1];
	scanf("%d %d %d", &n, &q, &k);
	for(int i=0; i<n; i++) scanf("%lld", &a[i]);
	b[0] = a[i]-1;
	c[0] = b[0];
	a[n] = k+1;
	for(int i=1; i<n; i++) {
		b[i] = a[i+1] - a[i-1] - 2;
		c[i] = b[i] + c[i-1];
	}
	// for(int i=0; i<n; i++) {
	// 	printf("%d ", b[i]);
	// }
	// printf("\n");
	// for(int i=0; i<n; i++) {
	// 	printf("%d ", c[i]);
	// }
	// printf("\n");
	for(int i=0; i<q; i++) {
		scanf("%lld %lld", &x, &y);
		if(x==y) {
			printf("%d\n", k - 1);
			continue;
		}
		x--; y--;
		// printf("%d %d %d\n", a[x+1]-2, k-a[y-1]-1, c[y-1]-c[x]);
		ans = a[x+1]-2 + k-a[y-1]-1 + c[y-1]-c[x];
		printf("%lld\n", ans);
	} 
}