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

typedef map<int,map<int,int> > graph;
typedef vector<int> vi;

vi dijkstra( graph g, int source, int vertices ) {
	priority_queue<pp > q;
	vector<int> dis( vertices+9, (int)10e9 );
	dis[source] = 0;
	q.push( make_pair( dis[source], source ) );
	
	while( !q.empty() ) {
		pp c = q.top();
		q.pop();
		int u = c.Y;

		for( auto i : g[u] ) {
			int v = i.X;
			debug( u, v );
			debug( dis );
			if( dis[v] > dis[u] + i.Y ) {
				dis[v] = dis[u] + i.Y;
				q.push( make_pair(dis[v], v) );
			}
		}
	}
	return dis;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, pos;
	cin >> t;
	while(t--){
		cin >> n >> m;
		graph g;
		for(int i=0; i<m; i++) {
	    	cin >> x >> y >> z;
	    	g[x][y] = z;
	    	g[y][x] = z;
	    }

	    vi distances = dijkstra( g, 1, n );
    	
	}
}

