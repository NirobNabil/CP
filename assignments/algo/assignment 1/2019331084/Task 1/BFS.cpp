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


/////////// Solution to LOJ 1009 //////////////

map<int, map<int,int> > g;
unordered_map<int,int> v;
vector<int> r = {0,0};

int bfs(int i) {
	if(v[i]) return 0;
	fill(r.A(), r.B(), 0);
	queue<pp> q;
	q.push({i, 0});
	while(!q.empty()) {
		auto nd = q.front();
		if( !v[nd.X] ) {
			for( auto i : g[nd.X] ) 
				q.push({i.X, !nd.Y});
			r[nd.Y]++;
			v[nd.X] = true;
		}
		q.pop();
	}
	return max(r[0], r[1]);
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
			ans += bfs(i);
		}
		printf("Case %d: %d\n", it, ans);
	}
}