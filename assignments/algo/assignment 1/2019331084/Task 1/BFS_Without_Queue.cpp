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


//////////// solution to loj 1009 /////////////

map<int, map<int,int> > g;
unordered_map<int,int> v;
vector<int> r = {0,0};

void dfs(int nd, int lvl) {
	if(v[nd]) return;
	v[nd] = true;
	for( auto i : g[nd] ) {
		dfs(i.X, !lvl);
	}
	r[lvl]++;
	return;
}


int main(){
	int t;
	scanf("%d", &t);
	for(int it = 1; it<=t; it++) {
		int n;
		v.clear();
		g.clear();
		scanf("%d", &n);
		set<int> s;
		int x, y;
		for(int i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			s.insert(x); s.insert(y);
			g[x][y] = 1;
			g[y][x] = 1;
		}
		int ans = 0;
		for( auto i:s ) {
			fill(r.A(), r.B(), 0);
			bfs(i, 0);
			ans += max(r[0], r[1]);
		}
		printf("Case %d: %d\n", it, ans);
	}
}