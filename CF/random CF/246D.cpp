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

map<int, map<int,int> > graph;
vector<int> c;

int dfs(int i) {
	int x = 0;
	for( auto ix : graph[i] ) 
		if( c[i] != c[ix.X] ) 
			x++;

	return x;
}

int main(){
	int i, ix, t, n, m, k, p, q, x, y, z;
	scanf("%d %d", &n, &m);
	
	c.clear();
	c.resize(n+9);
	for(int i=1; i<=n; i++) {
    	scanf("%d", &c[i]);
    }
    
    for(int i=1; i<=m; i++) {
    	scanf("%d %d", &x, &y);
    	graph[x][y] = 1;
    	graph[y][x] = 1;
    } 

    map<int, int> gg;
    int ans = -1;
    for(int i=1; i<=n; i++) {
    	gg[c[i]] += dfs(i);
    }

    int mx = 0;
    for(auto i:gg) {
    	if(mx < i.Y) {
    		mx = i.Y;
    		ans = i.X;
    	}
    }

    cout << ans << "\n";
}