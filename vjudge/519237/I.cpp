
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



void dfs( vector< vector<int > > &g, vector< int > &vis, int node ) {

    if( vis[node] ) return;

    vis[node] = true;

    for( auto i : g[node] ) {
        
        dfs( g, vis, i );

    }
    
}




int main(){
    int i, ix, t, n, m, k, l, p, q, gg, x, y, z;
    
    cin >> t;

    while( t-- ) {

        cin >> n >> m >> l;

        vector<vector<int> > g(n+1);
        vector<int> vis(n+1, 0);

        for( int i=0; i<m;   i++ ) {
            cin >> x >> y;
            g[x].push_back( y );
        }

        for( int i=0; i<l; i++ ) {
            cin >> x;
            dfs( g, vis, x );
        }

        
        int ans = 0;
        for( int i=0; i<vis.size(); i++ ) {
            ans += vis[i];
        }

        cout << ans << "\n";

    }
    
}

// 5 5
// wlwww
// wwllw
// wwwww
// wllww
// wllll
// 1 3
