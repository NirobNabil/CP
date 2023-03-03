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


#define rev(s,r,i) ( r ? s.size()-1 -i : i )

const ll mx = LONG_MAX*(ll)10000009;

int i, ix, t, n, m, k, p, q, gg, x, y, z;
ll dp[1000009][2];
vector<int> c(n);
vector<string> a(n);

bool cmp( string &a, string &b, bool ar, bool br ) {
	for(int i=0; i<a.size() && i<b.size(); i++) {
		if( a[ rev(a,ar,i) ] < b[ rev(b,br,i) ] ) return 1;
		if( a[ rev(a,ar,i) ] > b[ rev(b,br,i) ] ) return 0;
	} 

	if( a.size() > b.size() ) return 0;

	return 1;
}

ll chk( int i, int p ) {

	if( i >=n ) return 0;
	if( dp[i][p] != -1 ) return dp[i][p];

	dp[i][p] = mx;
	if( cmp(a[i-1], a[i], p, 0) ) 
		dp[i][p] = min( dp[i][p], chk( i+1, 0 ) );

	if( cmp(a[i-1], a[i], p, 1) ) 
		dp[i][p] = min( dp[i][p], chk( i+1, 1 )+c[i] );

	debug(i,p,dp[i][p]);

	return dp[i][p];
 
}


int main(){

	ios_base::sync_with_stdio(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	c.resize(n);
	a.resize(n);
	for(int i=0; i<n; i++) {
		cin >> c[i];
    }
    for(int i=0; i<n; i++) {
    	cin >> a[i];
    }

    ll ans = min( chk(1,0), chk(1,1)+c[0] );

    if( ans >= mx || ans < 0 ) cout << -1 << "\n";
    else cout << ans << "\n";

}