#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
ll k, n, m, x, y, p, l;
unordered_map<ll,unordered_map<ll,ll> > adj;
map<ll, ll> below;

ll dfs(ll x, ll p) {
	ll gg=1;
	for(auto i:adj[x]){
		if(i.X!=p) gg+=dfs(i.X, x);
	}
	// printf("%d - %d\n", x, gg);
	below[x]=gg*(n-gg);
	return gg;
}

int main(){
	ll t;
	ll mod = 1000000000 +7;
	scanf("%lld", &t);
	while(t--){
		adj.clear();
		below.clear();
		scanf("%d", &n);
		for(ll i=0; i<n-1; i++) {
			scanf("%d %d", &x, &y);
			adj[x][y]=1;
			adj[y][x]=1;
		}
		scanf("%d", &m);
		vector<ll> p(m);
		for(auto &i:p) cin >> i;
		// for(auto i:in) cout << i << "\n";
		sort(p.begin(), p.end(), greater<int>());

		dfs(1,0);
		
		// for(auto i:below) printf("%d- %d\n", i.X, i.Y);
		vector <pair<ll,ll> > xd;
		for(auto i:below) {
			xd.push_back({i.Y, i.X});
		}

		sort(xd.begin(), xd.end(), greater<pair<ll,ll> >());
		vector<ll> ans(n);
		fill(ans.begin(), ans.end(), 1);

		// for(auto i:p) printf("%d\n", i);
		ll iy=0, ix=0;
		for(; m-ix>=n; ix++) ans[0] *= p[ix], ans[0] %= mod;
		while(ix<p.size() && iy<n) {
			ans[iy] *= p[ix++];
			ans[iy] %= mod;
			iy++;
		}
		ll jkl = 0;
		// prllf("%d/%d/%d ", ans[i], i, xd[i].X),
		for(ll i=0; i<n-1; i++) jkl += (ans[i]*xd[i].X)%mod, jkl %= mod;
		printf("%lld\n", jkl);
	}
}