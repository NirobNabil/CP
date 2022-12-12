
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

int mx = 30009;
int i, ix, u, v, t, n, m, k, p, q, gg, x, y, z;

vector<int> w(mx);
vector< vector<int> > g(mx);
vector<int> parent(mx);
vector<pair<pp,pp> > fromup(mx), fromdown(mx), final(mx);
int root = 1;


vector<int> dis(mx), vis(mx); 
void dfs(int node, int count){
    if( node > n || vis[node] ) return;
    vis[node] = 1;
    //debug(node,count);
    dis[node] = count;
    for( auto i:g[node] ){
        dfs( i, count+1);
    }
}

pp get_nodes() {
   fill(dis.A(), dis.B(), 0);
   fill(vis.A(), vis.B(), 0);
   dfs(1, 0);
   int n1, n2;
   int md = 0;
   for( int i=1; i<=n; i++ ) if( dis[i] > md ) n1 = i, md = dis[i];
   fill(dis.A(), dis.B(), 0);
   fill(vis.A(), vis.B(), 0);
   dfs(n1, 0);
   md = 0;
   for( int i=1; i<=n; i++ ) if( dis[i] > md ) n2 = i, md = dis[i];
    return make_pair(n1, n2);
}

void bfs() {
    queue<pp> q;
    stack<int> s;
    parent.clear();
    fromup.clear();
    fromdown.clear();
    final.clear();
    vector<vector<int> > level(n+9);

    q.push( {root, 0} );
    s.push( root );
    parent[root] = -1;
    while( !q.empty() ) {
        int node = q.front().X;
        int lvl = q.front().Y+1;
        q.pop();
        for( auto cur:g[node] ) {
            if( cur == parent[node] ) continue;
            q.push( {cur,lvl} );
            level[lvl].push_back(cur);
            parent[ cur ] = node;
            fromup[ cur ].X.X += fromup[node].X.Y+w[node];
            fromup[ cur ].X.Y += fromup[node].X.X;
            fromup[ cur ].Y.X += fromup[node].Y.Y+1;
            fromup[ cur ].Y.Y += fromup[node].Y.X;
 
            //debug( cur, fromup[cur].X, fromup[cur].Y );
        }

    }
    
    for( int i=n; i>=0; i-- ){
        for( auto node:level[i] ){
            if( node == root ) continue;
            int cur = parent[node];
            fromdown[cur].X.X += fromdown[node].X.Y+w[node];
            fromdown[cur].X.Y += fromdown[node].X.X;
            fromdown[cur].Y.X += fromdown[node].Y.Y+1;
            fromdown[cur].Y.Y += fromdown[node].Y.X;
        }
    }
        
    for(int i=1; i<=n; i++) {
        final[i].X = { fromup[i].X.X + fromdown[i].X.X, fromup[i].X.Y + fromdown[i].X.Y };
        final[i].Y = { fromup[i].Y.X + fromdown[i].Y.X, fromup[i].Y.Y + fromdown[i].Y.Y };
    } 
    
    //debug("gg");
}

int main(){
    scanf("%d", &t);
    for(int tc=1; tc<=t; tc++) {
        g.clear();
        w.clear();
        scanf("%d", &n);
        w.resize(n+9);
        g.resize(n+9);
        for(int i=1; i<=n; i++) {
    	    scanf("%d", &w[i]);
        }
        for( int i=0; i<n-1; i++ ) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        pp qqw = get_nodes();
        root = qqw.X;
        bfs();
        
        for( int i=1; i<=n; i++ ) {
            debug( i, final[i] );
        }
        
        int finalans = INT_MIN;
        int finali = 1;
        for(int i=1; i<=n; i++) {
            int e = final[i].X.X, o = final[i].X.Y;
            int ec = final[i].Y.X, oc = final[i].Y.Y;
            
            int ans = 0;
            ans -= (ec-oc)*w[i];

            ans += e;
            ans -= o;
            if( finalans < ans ) {
                finali = i;
                finalans = ans;
            }
        } 
        
        printf("Case %d: %d\n", tc, finali);
    }
}

