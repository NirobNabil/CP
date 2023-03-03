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


vector<int> coins = {5, 10, 20, 50, 100, 200};
vector<int> mcoins = {};

int dp[6][10000][509];
int dp2[509];

int chk2( int c ) {
	if( c < 0 ) return INT_MAX ;
	if( c == 0 ) return 0;
	if( dp2[c] != INT_MAX ) return dp2[c];

	for( auto i : coins ) {
		dp2[c] = min( (ll)dp2[c], (ll)chk2( c - i ) + (ll)1 );
	}

}


int chk( int i, int count, int c ) {
	if( c == 0 ) return 0;
	if( dp[i][count][c] != INT_MAX ) return dp[i][count][c];

	if( c < 0 ) dp[i][count][c] = chk2(c*-1);  

	return dp[i][count][c] = min( {dp[i][count][c], chk( i+1, 0, c - mcoins[i]*count ) + 1, chk( i, count+1, c ) } );

}



int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	while(1){
		int bb = 0;
		memset(dp, INT_MAX, sizeof(dp));
		for(int i=0; i<6; i++) {
	    	scanf("%d", &x);
	    	bb = x | bb;
	    	while(x--)
	    		mcoins.push_back( coins[i] );
	    }
	    
	    if(!bb) return 0;

	    float change;
	    scanf("%f", &change);
	    change *= 100;
	    debug((int)change);

	    printf("%d\n", chk2((int)change));

	}
}