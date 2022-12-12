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

typedef map<int, map<int,int> > graph;
typedef vector<int> vi;

// returns -1 if path doesnt exist
int get_initial_node( graph g ) {
	int odd_count = 0;
	int initial_node = -1;
	for( auto i:g ) {
		if( i.Y.size() % 2 == 1 ) 
			odd_count++, initial_node = i.X;
	}
	if( odd_count == 0 ) return g.begin()->X;
	else if( odd_count == 2 ) return initial_node;
	else return -1;
}

void dfs( int u, graph &g, int &visited_count, map<int,int> &visited, pp erased_edge ) {
	if( visited[u] ) return;
	visited[u] = true;

	visited_count++;
	for( auto i:g[u] ) {
		if( u == erased_edge.X && i.X == erased_edge.Y ) continue;
		if( i.X == erased_edge.X && u == erased_edge.Y ) continue;
		dfs( i.X, g, visited_count, visited, erased_edge );
	}
}

bool check_bridge( int u, int v, graph &g ) {
	map<int,int> visited;
	int prev_visited_count = 0;
	dfs( 0, g, prev_visited_count, visited, make_pair(0,0) );

	visited.clear();
	int cur_visited_count = 0;
	dfs( 0, g, cur_visited_count, visited, make_pair(u,v) );


	if( cur_visited_count < prev_visited_count ) return true;
	else return false;	 
}
 
void fleury(int u, graph &g, vi &path) {

	path.push_back(u);
	if( g[u].size() == 0 ) return;

	int v = -1;
	for( auto i : g[u] ) {
		if( check_bridge( u, i.X, g ) ) continue;
		v = i.X;
	}
	if( v == -1 ) v = g[u].begin()->X;
	
	g[u].erase(v);
	g[v].erase(u);

	fleury( v, g, path );

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
	    	g[v][u] = 1;
	    }
    // for(auto i:g) debug(i.X, i.Y);

	    int initial_node = get_initial_node(g);
		if( initial_node == -1 ) cout << "DOESNT EXIST\n";
	    vi path;
	    fleury( initial_node, g, path );

	    for( auto i : path ) {
	    	cout << i << " ";
	    }
	    cout << "\n";

	}
}