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
#define ABS(a) ((a)<0?(a)*-1:a)
ll i, ix, t, n, a[S1], b[S1], c[S1], d[S1], e[S1];


int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		rep(i, 0, n) scanf("%lld", &c[i]);
		rep(i, 0, n) scanf("%lld", &a[i]);
		rep(i, 0, n) scanf("%lld", &b[i]);
		e[0] = (ll)INT_MIN*2;
		for(int i=1; i<n; i++) {
			// printf("%lld\n", ABS(a[i]-b[i]));
			if(a[i]==b[i]) { e[i]=c[i]+1; continue; }
			e[i] = max(e[i-1]+c[i]-ABS(a[i]-b[i])+1, c[i]+ABS(a[i]-b[i])+1);
		}
		ll m = 0;
		for(int i=1; i<n; i++) m = max(m, e[i]);
		printf("%lld\n", m);
	}
}