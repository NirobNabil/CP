#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int main(){
	int i, ix, t, n;
	ll x, y, z;
	scanf("%d", &t);
	for(int tc=0; tc<t; tc++) {
		scanf("%d", &n);
		printf("Case %d: ", tc+1);
		vector<ll> a;
		for(int i=0; i<n; i++) {
			scanf("%lld", &x);
			a.pb(x);
		}
		sort(a.A(), a.B());
		printf("%lld\n", a[0]*a.back());
	}
}