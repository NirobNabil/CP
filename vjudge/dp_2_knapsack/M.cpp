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


int dp[100][5];
int i, ix, t, n, m, k, p, q, gg, x, y, z;
vector<int> a(n);

int chk( int i, int p ) {

	if( i >= n ) return 0;
	if( dp[i][p] != -1 ) return dp[i][p];

	dp[i][p] = chk( i+1, 0 ) +1;

	if( (a[i]==1 || a[i]==3) && p != 1 )
		dp[i][p] = min( dp[i][p], chk(i+1, 1) );

	if( (a[i]==2 || a[i]==3) && p != 2 )
		dp[i][p] = min( dp[i][p], chk(i+1, 2) );

	return dp[i][p];

}


int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	a.resize(n);
	for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    printf("%d\n", chk(0,0));
}