#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define CEIL(a,b) (a%b?a/b+1:a/b)

int main(){
	ll i, ix, t, n, A, B;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &A, &B, &n);
		vector<pair<ll, ll> > v(n);
		rep(i, 0, n) scanf("%lld", &v[i].X);
		rep(i, 0, n) scanf("%lld", &v[i].Y);
		sort(v.begin(), v.end());
		bool p=1;
		for(int i=0; i<n; i++) {
			B -= v[i].X*CEIL(v[i].Y, A);
			// printf("%lld %lld %lld\n", v[i].X, v[i].Y, B);
		}
		if(B <= v[n-1].X*-1) p = 0;
		if(p) printf("YES\n");
		else printf("NO\n");
	}
}