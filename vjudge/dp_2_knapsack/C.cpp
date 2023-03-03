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

int i, ix, t, n, m, k, p, q, gg, x, y, z;

int mv;
int dp[109][100009];
vector<int> a;

int chk( int i, int v ) {

	if( i >= n ) return min( abs(2*v - mv), abs(mv - 2*v) );
	if( dp[i][v] != -1 ) return dp[i][v];

	return dp[i][v] = min( chk(i+1,v), chk(i+1,v+a[i]) );

}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mv = 0;
		a.resize(n);
		a.clear();
		memset( dp, -1, sizeof(dp) );
		for(int i=0; i<n; i++) {
	    	scanf("%d", &a[i]);
	    	mv += a[i];
	    }

	    printf("%d\n", chk( 0, 0 ));
	}
}