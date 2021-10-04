#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define item pair<pair<int,int>,int>
#define X first
#define Y second
int k, n, m, x, y, p, l;
map<int, map<int,int> > adj;
map<int, int> below, parent;
map<int, vector<int> > centeroidness;

int dfs(int x, int p) {
	int a = 0, g;
	parent[x] = p;
	for(auto i:adj[x]) {
		// printf("%d\n", i.X);
		if(i.X!=p) {
			// printf("%d\n", i.X);
			g = dfs(i.X, x);
			below[x] += g;
			a = max(a, g);
		}
	}
	a = max(n - below[x] - 1, a);
	// printf("%d-%d-%d\n", x,a,below[x]);
	centeroidness[a].push_back(x);
	return below[x]+1;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		adj.clear();
		below.clear();
		parent.clear();
		centeroidness.clear();
		scanf("%d", &n);
		for(int i=1; i<n; i++) {
			scanf("%d %d", &x, &y);
			adj[x][y]=1;
			adj[y][x]=1;
		}			
		dfs(1, 0);
		vector<int> g = centeroidness.begin() -> Y;
		for(auto i:adj[g[0]]) {
			if(i.X==parent[g[0]] && g.size()!=1) continue;
			else {
				printf("%d %d\n", g[0], i.X);
				if(g.size()!=1) printf("%d %d\n", g[1], i.X);
				else printf("%d %d\n", g[0], i.X);
				break;
			}
		}
	}
	
}