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

ll dp[109][109];
// vector<vector<int> > grid(100, vector<int>(100));
ll i, ix, t, n, m, k, p, q, gg, x, y, z;

ll chk(ll x, ll y) {
	if(x == n && y == m) return 0;
	if(x > n || y > m ) return INT_MAX;
	if(dp[x][y]) return dp[x][y];
	dp[x][y] = min(chk(x+1, y)+y, chk(x, y+1)+x);
	return dp[x][y]; 
}

int main(){
	scanf("%lld", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		scanf("%lld %lld %lld", &n, &m, &k);
    k -= chk(1,1);
    // printf("%d\n", k);
		if(k == 0) printf("YES\n");
		else printf("NO\n");
	}
}