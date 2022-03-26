#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


map<int, map<int, int> > g, bridge;
map<int, int> vis, low, num, parent;
int root = 0;
int lvl = 0;
int t, n, m, k, p, q, gg, x, y, z, pos;


// tarjan
void dfs( int nd) {
	vis[nd] = true;
	num[nd] = low[nd] = lvl++;

	for ( auto i:g[nd] ) {

		// checking if the edge is disabled
		if(i.Y == 0) continue;

		if( !vis[i.X] ) {

			parent[i.X] = nd;

			dfs( i.X );

			if( low[i.X] > low[nd] ) {
				bridge[nd][i.X] = true;
			}

			low[nd] = min(low[nd], low[i.X]);

		} else if ( parent[nd] != i.X ){
			low[nd] = min(low[nd], num[i.X]);
		}
	}
}

void setBridges(int rt) {
	lvl = 0;
	vis.clear();
	low.clear();
	num.clear();
	parent.clear();
	bridge.clear();
	dfs( rt );
}


vector<int> getEulerPath() {

	// checking if path exists
	root = 0;
	int odd_count = 0;
	for(int i=0; i<n; i++) {
		if( g[i].size() % 2 == 1 ) root = i, odd_count++;
	}
	if( odd_count != 2 && odd_count != 0 ) return vector<int>();



	// generating path
	int processed = 0;
	vector<int> path;
	int u = root;
	while( processed <= m ) {
		set<pp> candidates;
		path.push_back(u);
		setBridges(u);

		for( auto i:g[u] ) {
			if( i.Y == 0 ) continue;
			candidates.insert( {bridge[u][i.X], i.X} );
		}
		if ( candidates.size() ) {
			int v = candidates.begin()->Y;
			g[u][v] = 0;
			g[v][u] = 0;
			u = v;
		}

		processed++;
	}

	return path;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<m; i++) {
    	cin >> x >> y;
    	g[x][y] = 1;
    	g[y][x] = 1;
	}

	vector<int> ans = getEulerPath();

	if(ans.size()==0) cout << "Euler Path doesn't exist.";
	else {
		cout << "Euler Path exists:\n" << ans[0];
		for(int i=1; i<ans.size(); i++)  {
			cout << " - " << ans[i];
		}
	}
	

}