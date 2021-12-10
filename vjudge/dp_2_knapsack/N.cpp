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
ll dp[100009];
vector<ll> a;
map<ll,ll> g;

ll chk( int i ) {

	if( i >= a.size() ) return 0;
	if( dp[i] ) return dp[i];

	if( i+1<n && a[i+1]==a[i]+1 ) {
		return dp[i] = max( chk(i+1), chk( i+2 )+g[a[i]]*a[i] ); 
	}else return dp[i] = chk( i+1 )+g[a[i]]*a[i];

}


int main(){
	scanf("%d", &n);
	a.resize(n);
	for(int i=0; i<n; i++) {
    	scanf("%lld", &a[i]);
    	g[a[i]]++;
    }
    sort(a.A(), a.B());
    a.resize(unique(a.A(), a.B()) - a.A());
    printf("%lld\n", chk(0));
}