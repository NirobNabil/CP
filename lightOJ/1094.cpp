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


map<int,int> lvl;
map<int,map<int,int> > g;

void dfs(int node, int l) {
	if(lvl[node]) return;
	lvl[node] = l;
 	for(auto i:g[node]) {
		dfs(i.X, l + 1);
	}
	return;
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, w, pos;
	cin >> t;
	for(int it=1; it<=t; it++) {
		cin >> n;

		for(int i=0; i<n-1; i++) {
	    	cin >> x >> y >> w;
	    	g[x][y] = w;
	    	g[y][x] = w;
	    }

	    dfs(x,1);
	    int a = x;
	    for(auto i:lvl) 
	    	if( lvl[a] < lvl[i.X] ) a = i.X;	

	    lvl.clear();

	    dfs(a,1);
	    for(auto i:lvl) 
	    	if( lvl[a] < lvl[i.X] ) a = i.X;

	    printf("Case %d: %d\n", it, lvl[a]-1);
	}
}