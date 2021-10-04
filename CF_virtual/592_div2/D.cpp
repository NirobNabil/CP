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

map<ll, map<ll,ll> > edge;
ll count[S1], color[S1];
vector<vector<ll> > cost(4);
vector<ll> colors = {0,1,2};
vector<ll> vcolors(S1), ansvcolors;


ll dfs(ll c, ll p, ll clr) {
	// printf("%d %d %d\n", c, clr, cost[colors[clr]][c-1]);
	// cerr << c << " " << (clr+1)%3 << endl;
	ll tcost = cost[colors[clr]][c-1];
	vcolors[c] = colors[clr];
	// cerr << "gg " << cost[colors[clr]][c-1] << endl;
	for(auto ix:edge[c]) {
		if(ix.X==p) continue;
		tcost += dfs(ix.X, c, (clr+1)%3);
	}
	return tcost;
}

int main(){
	ll i, ix, x,y, n, xx;
	scanf("%lld", &n);
	for(ll i=0; i<3; i++) {
		for(ll ix=1; ix<=n; ix++) {
			scanf("%lld", &x);
			cost[i].push_back(x);
		} 
	}
	for(ll i=0; i<n; i++) {
		scanf("%lld %lld", &x, &y);
		edge[x][y] = 1;
		edge[y][x] = 1;
	}
	// for(auto i:edge) {
	// 	for(auto ix:i.Y) {
	// 		printf("%lld %lld\n", i.X, ix.X);
	// 	}
	// }
	ll ans=LONG_LONG_MAX, tans=LONG_LONG_MAX;
	for(ll i=1; i<=n; i++) {
		if(edge[i].size()>2) {
			printf("-1\n");
			return 0;
		}
	}
	for(ll i=0; i<n; i++) {
		if(edge[i].size()==1) {
			do {
				tans = dfs(i, -1, 0);
				if(tans<ans) {
					ansvcolors = vcolors;
					ans = tans;
				}
			}while(next_permutation(colors.begin(), colors.end()));
			printf("%lld\n", ans);
			for(ll i=1; i<=n; i++) printf("%lld ", ansvcolors[i]+1); 
			printf("\n");
			return 0;
		}	
	}
	return 0;
}