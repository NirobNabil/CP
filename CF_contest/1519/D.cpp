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

ll dp[5009][5009];
vector<ll> a(5009), b(5009);
vector<ll> c(5009);

ll chk(int x, int y) {
	if(x == y) return a[x] * b[x];
	if(x > y) return 0;
	if(dp[x][y]) return dp[x][y];
	dp[x][y] = a[x] * b[y] + chk(x+1, y-1) + a[y] * b[x];
	// debug(x, y, dp[x][y]);
	return dp[x][y]; 
}

int main(){
	ll i, ix, t, n, m, k, p, q, gg, x, y, z;
	// scanf("%d", &t);
	// while(t--){
		// a.clear();
		// b.clear();
		// c.clear();
		scanf("%lld", &n);
		for(int i=0; i<n; i++) {
    	scanf("%lld", &a[i]);
    }
		for(int i=0; i<n; i++) {
    	scanf("%lld", &b[i]);
    }
    c[0] = a[0] * b[0];
    for(int i=1; i<n; i++) {
    	c[i] = c[i-1] + a[i] * b[i];
    }
    ll mx = c[n-1];
    // debug(c)
  	// mx = max(mx, c[n-1] - c[i] + a[i] * b[i]);
    for(int i=0; i<n-1; i++) {
    	for(int ix=n-1; ix>=i; ix--) {
    		// debug(i+1, ix-1, chk(i+1, ix-1));
    		mx = max(mx, 
    			   (i > 0 ? c[i-1] : 0)
    			 + chk(i, ix) 
    			 + (ix<n-1 ? c[n-1]-c[ix] : 0));
    		// debug((i > 1 ? c[i] : 0));
    	} 
    }
    printf("%lld\n", mx);
	// }
}