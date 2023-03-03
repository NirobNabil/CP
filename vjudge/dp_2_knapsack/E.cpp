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

int a[25];
int i, ix, t, n=21, m, k, p, q, x, y, z;
ll dp[25][30009];
ll mw;

ll chk( int i, int v ) {

	if( v == 0 ) return 1;
	if( v < 0 || i >= n ) return 0;
	if( dp[i][v] != -1 ) return dp[i][v];

	return dp[i][v] = chk( i+1, v ) + chk( i, v-a[i] );

}


int main(){
	memset(dp, -1, sizeof(dp));
	
	for(int i=1; i<22; i++) 
		a[i-1] = pow(i,3); 

	for(int i=1; i<22; i++) 
		debug( a[i] ); 

	while(scanf("%lld", &mw) == 1){
		debug(mw);
		printf("%lld\n", chk( 0, mw ));
	}
}