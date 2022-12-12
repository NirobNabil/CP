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


typedef map<int, map<int, bool> > graph;


void dfs(int u, graph &g, vector<int> &disc, vector<int> &low, map<int, bool> &sg, vector<int> &st, int count, vector<vector<int> > &sccs ) {

	if( disc[u] != -1 ) return;

	disc[u] = ++count;
	low[u] = count;
	sg[u] = true; 
	st.push_back(u);

	for( auto i:g[u] ) {
		int v = i.X;
		dfs( v, g, disc, low, sg, st, count, sccs);
		if( sg[v] ) low[u] = min(low[u], low[v]);
	}

	if( disc[u] == low[u] ) {
		vector<int> scc;
		while( 1 ) {
			scc.push_back(st.back());
			sg.erase(st.back());  // popping from sg because popped from stack
			st.pop_back();
			if( scc.back() == u ) break;
		}
		sccs.push_back(scc);
	}
}

vector<vector<int> > tarjan( graph g, int vertices ) {
	vector<vector<int> > sccs;
	vector<int> low(vertices, -1), disc(vertices, -1);
	map<int, bool> sg;  // sg is to check if node is in stack
	vector<int> st;  // the stack
	int count = -1;

	for( auto i : g ) {
		dfs( i.X, g, disc, low, sg, st, count, sccs );
	}
	return sccs;
}





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, pos, u, v;
	t = 1;
	while(t--){
		cin >> n >> m;
		graph g;
		for(int i=0; i<m; i++) {
	    	cin >> u >> v;
	    	g[u][v] = 1;
	    }
	    for( auto i:g ) debug(i.X, i.Y);
	    vector<vector<int> > res = tarjan( g, n );
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