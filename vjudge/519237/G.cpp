
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


vector< ll> dp( 1009, -1 );
vector< vector<int> > divisors;

ll dfs( int node, int t ) {

    if( node == t ) return 0;
    if( node > t ) return INT_MAX;

    if( dp[node] != -1 ) return dp[node];

    dp[node] = INT_MAX;
    for( auto i : divisors[node] ) {
        dp[node] = min( dp[node], dfs( node+i, t )+(ll)1 );
    }
    
    return dp[node];

}




int main(){
    int i, ix, t, n, m, k, p, q, gg, l, x, y, z;
    
    n = 1000;
    divisors.resize(n+1);
    for( int i=2; i<=n; i++ ) {
        if( divisors[i].size() > 0 ) continue;
        for( int ix=i+i; ix<=n; ix += i ) {
            divisors[ix].push_back(i);
        }
    }

    scanf("%d", &t);
    for( int tt = 1; tt<=t; tt++ ) {

        scanf("%d %d", &n, &l);
    
        fill( dp.A(), dp.B(), -1 );
        int steps = dfs( n, l );
        printf("Case %d: ", tt);

        if( steps >= INT_MAX ) printf("%d\n", -1);
        else printf("%d\n", steps);
    
    }

}































