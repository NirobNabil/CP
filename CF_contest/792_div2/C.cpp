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


map<int,map<int,int> > g;
map<int, int> depth_node;
int shortest_node;
void dfs( int x, int p, int d) {
	// debug(x, p, d);
	if( g[x].size() <= 2 && ( x!=1 || g[x].size()==1 ) ) {
		if( depth_node[d] && g[depth_node[d]].size()==1 ) return;
		depth_node[d] = x;
		return;
	}

	for( auto i:g[x] ) {
		if( i.X == p ) continue;
		dfs(i.X, x, d+1);
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, pos;
	cin >> t;
	while(t--){
		depth_node.clear();
		g.clear();
		cin >> n;
		int i, j;
		for(int x=0; x<n-1; x++) {
	    	cin >> i >> j;
	    	g[i][j] = 1;
	    	g[j][i] = 1;
	    	// debug(i,j,n);
	    }

    	dfs(1, 0, 1);

    	int d = 1;
    	for(; d<n; d++) {
    		if( depth_node[d] ) {
    			shortest_node = depth_node[d];
    			break;
    		}
    	}
    	debug(shortest_node, d);

    	// debug(depth_node);
    	if( shortest_node == 1 ) cout << n-2 << "\n";
    	else cout << n-d*2 + ( g[shortest_node].size() == 1 ? 1 : 0 ) << "\n";
	}
}