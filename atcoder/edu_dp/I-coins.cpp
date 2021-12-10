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

#define CEIL(n,x) ( n%x ? (n/x) + 1 : n/x )

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




int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	cin >> n;
	vector<double> a(n+9);
	vector<vector<double> > dp(n+1, vector<double>(n+1) );
	for(int i=1; i<=n; i++) {
		cin >> a[i];
    }

    // debug(a);
    dp[n][0] = (double)1 - a[n];
    dp[n][1] = a[n];
    for(int i=n-1; i>0; i--) {
    	dp[i][0] = ((double)1 - a[i]) * dp[i+1][0];
    	for(int ix=1; ix<=(n-i+1); ix++) {
	    	dp[i][ix] = ((double)1 - a[i]) * dp[i+1][ix]
	    					+ ( a[i] * dp[i+1][ix-1] );
	    	// debug(i,ix,dp[i][ix]);
    	} 
    }

    double ans = 0;
    for(int i=n/2 +1; i<=n; i++) {
    	ans += dp[1][i];
    }

    // debug(dp);
    cout.precision(10);
    cout << ans << "\n";
}