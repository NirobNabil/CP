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


void reverse(map<int,map<int,int> > &g ) {
	map<int, map<int, int> > tg;
	for( auto i:g ) {
		int u = i.X;
		for( auto ix : i.Y ) {
			int v = ix.X;
			tg[v][u] = ix.Y;
		}
	}
	g = tg;
}

map<int, bool> visited;
void dfs(int n, map<int,map<int,int> > &g, vector<int> &s) {
	if( visited[n] ) return;
	visited[n] = true;
	for( auto i : g[n] ) {
		dfs( i.X, g, s );
	}
	s.push_back(n);
}

vector<vector<int> > kosaraju(map<int, map<int,int> > g) {
	vector<int> s;
	visited.clear();
	dfs( 0, g, s );
	reverse( s.A(), s.B() );
	reverse( g );
	
	vector<vector<int> > res;
	visited.clear();
	for( auto i:s ) {
		if( visited[i] ) continue;
		vector<int> scc;
		dfs( i, g, scc );
		res.push_back( scc );
	}
	return res;
}	


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, pos, u, v;
	t = 1;
	while(t--){
		cin >> n >> m;
		map<int, map<int,int> > g;
		for(int i=0; i<m; i++) {
	    	cin >> u >> v;
	    	g[u][v] = 1;
	    }
	    vector<vector<int> > res = kosaraju( g );
	    for( auto i:res ) {
	    	for( auto x : i ) cout << x << " ";
	    	cout << "\n";
	    }
	}
}


// 8 12
// 0 1
// 7 1
// 1 6
// 6 7
// 6 0
// 0 4
// 6 4
// 6 5
// 5 3
// 3 4
// 4 2
// 2 3