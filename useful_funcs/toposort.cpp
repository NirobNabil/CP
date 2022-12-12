
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


void dfs(int st, map<int, vector<int> > &g, vv &sorted, vv &vis) {

    if( vis[st] ) return;

    vis[st] = true;
    for( auto neighbor : g[st] )
        dfs( neighbor, g, sorted, vis );

    sorted.push_back(st);
}

vector<int> toposort( map<int, vector<int> > &g, int n ) {
    vector<int> sorted, vis(n+1, 0);

    for( auto i : g ) 
        dfs( i.X, g, sorted, vis );

    reverse(sorted.begin(), sorted.end());
    return sorted;
}


vector<int> kahn( map<int, vector<int> > &g, int n ) {

    priority_queue<int, vector<int>, greater<int> > q;
    map<int,int> in_deg;
    vector<int> ans;

    for( int i=1; i<=n; i++ )
        for( auto ix : g[i] )
            in_deg[ix]++;

    for( int i=1; i<=n; i++ ) 
        if( in_deg[i] == 0 ) 
            q.push( i );

    while( !q.empty() ) {
        int cur = q.top();
        q.pop();
        ans.push_back(cur);
        for( auto neighbor : g[cur] ) {
            in_deg[neighbor]--;
            if( in_deg[neighbor] == 0 ) 
                q.push(neighbor);
        }
    }

    return ans;
}


int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%d %d", &n, &m);

    map<int, vector<int> > g;

    for( int i=0; i<m; i++ ) {
        scanf("%d %d", &x, &z);
        for( int ix=0; ix<z; ix++ ) {
            scanf("%d", &y);
            g[y].push_back(x);
        }
    }

    vector<int> ans = kahn(g, n);

    for( auto i : ans ) printf("%d ", i);
    printf("\n");

}


