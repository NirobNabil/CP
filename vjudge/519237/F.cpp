
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


pp dfs( vector< vector<pair<int,int> > > &g, vector< int > &vis, int node ) {

    vis[node] = true;

    pair<int,int> farthest = {node,0};

    for( auto i : g[node] ) {
        if( vis[i.X] ) continue;
        pp dis = dfs( g, vis, i.X );
        dis.Y += i.Y;
        if( dis.Y > farthest.Y ) farthest = dis;
    }
    
    return farthest;

}




int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    
    scanf("%d", &t);

    for( int tt = 1; tt <= t; tt++ ) {

        scanf("%d", &n);

        vector<vector<pp> > g(n);
        vector<int> vis(n, 0);

        for( int i=0; i<n-1; i++ ) {
            scanf("%d %d %d", &x, &y, &z);
            g[x].push_back( make_pair(y,z) );
            g[y].push_back( make_pair(x,z) );
        }

        
        pp farthest = dfs( g, vis, 0 );

        fill(vis.A(), vis.B(), 0);
        farthest = dfs( g, vis, farthest.X );

        printf("Case %d: %d\n", tt, farthest.Y);
    }
    
}

