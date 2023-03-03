
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


char land = 'l';

vector<pair<int,int> > trav = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
};

void dfs( vector< string > &g, vector< vector<int> > &vis, int i, int j, int &total, int &n, int &m ) {

    if( j < 0 ) j += n;
    if( j >= n ) j -= n;

    if( i < 0 || i >= m || vis[i][j] || g[i][j] != land ) return;

    vis[i][j] = true;
    total++;

    for( auto p : trav ) {
        dfs( g, vis, i+p.X, j+p.Y, total, n, m );
    }
}


int floodfill( vector< string > &g, int n, int m, int i, int j ) {
    
    vector< vector<int> > vis( m, vector<int>(n, 0) );

    int ans = 0;

    dfs( g, vis, i, j, ans, n, m );
    ans = 0;

    for( int i = 0; i<m; i++ ) {
        for( int j = 0; j<n; j++ ) {
            int total = 0;
            dfs(g,vis,i,j,total,n,m);
            ans = max(total, ans);
        }
    }

    return ans;
}


int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    
    while( cin >> m >> n ) {

        vector<string> g(m);
        for( int i=0; i<m; i++ ) {
            cin >> g[i];
        }

        cin >> x >> y;

        land = g[x][y];

        cout << floodfill( g, n, m, x, y ) << "\n";
    
    }
    
}

// 5 5
// wlwww
// wwllw
// wwwww
// wllww
// wllll
// 1 3
