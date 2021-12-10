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

const int N = 10000;
int dp[N][3];
int c[N][3];


int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	for(int it=1; it<=t; it++) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
	    	scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
	    }
	    dp[n-1][0] = c[n-1][0];
	    dp[n-1][1] = c[n-1][1];
	    dp[n-1][2] = c[n-1][2];
	    for(int i=n-2; i>=0; i--) {
	    	for(int ix=0; ix<3; ix++) {
	    		dp[i][ix] = c[i][ix] + min( dp[i+1][(ix+1)%3], dp[i+1][(ix+2)%3] );
	    	} 
	    } 
	    
	    cout << "Case " << it << ": " << min( {dp[0][0], dp[0][1], dp[0][2]} ) << "\n";
	}
}