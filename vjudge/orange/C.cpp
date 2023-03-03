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


vector<int> a;
map<int,map<int,int> > tree;

map<int,int> vis;
vector<int> ans;
int i, ix, t, n, m, k, p, q, gg, x, y, z;

bool check_leaf(int node) {
	if(tree[node].size() == 1 && vis[tree[node].begin()->X]) return 1;
	else return 0;
}

void dfs(int node, int x) {
	if(vis[node]) return;

	x += a[node];
	if(x > m) return;

	if(!a[node]) x = 0; 

	vis[node] = 1;
	if(check_leaf(node)) {
		ans.push_back(node);
		return;
	}

	for(auto i:tree[node]) {
		dfs(i.X, x);
	}
}


int main(){
	cin >> n >> m;
	a.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
    }
    for(int i=0; i<n-1; i++) {
    	cin >> x >> y;
    	tree[x][y] = 1;
    	tree[y][x] = 1;
    } 
    dfs(1, 0);
    cout << ans.size();
}