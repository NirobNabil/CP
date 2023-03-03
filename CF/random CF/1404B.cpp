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
int i, ix, t, n, m, k, p, q, gg, x, y, z, da, db, a, b;
int v[S1];

int dfs(int n, int s) {
	if(s > da || v[n]) return 0;
	if(n == b) return 1;
	int ans = INT_MIN;
	v[n] = 1;
	for(auto i:g[n]) {
		ans = max(dfs(i.X, s+1), ans);
	}
	return ans;
}


pp dfs_d(int n) {
	int md = 0, ans = n;
	v[n] = 1;
	for(auto i:g[n]) {
		if(v[i.X]) continue;
		auto r = dfs_d(i.X);
		if(r.Y > md) {
			md = r.Y;
			ans = r.X;
		}
	}
	// printf("%d - %d %d\n", n, md, ans);
	return {ans, md+1};
}

int tree_diameter(map<int, map<int,int> > &g) {
	memset(v, 0, sizeof(v));
	int x = dfs_d(g.begin()->X).X; 
	// printf("x %d\n", x);
	memset(v, 0, sizeof(v));
	return dfs_d(x).Y-1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		g.clear();
		scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
		for(int i=0; i<n-1; i++) {
			scanf("%d %d", &x, &y);
			g[x][y] = 1;
			g[y][x] = 1;                                                                                                                                                                                                                                                                                      
		}
		int td = tree_diameter(g);
		if(td <= da*2) {
			printf("Alice\n");
			continue;
		}
		memset(v, 0, sizeof(v));
		if(dfs(a, 0)) {
			printf("Alice\n");
		}else {
			if(db > da*2) printf("Bob\n");
			else printf("Alice\n");
		}
		// printf("%d\n", tree_diameter(g));
    }
}