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

stack<int> st;
map<int,bool> visited;
map<int, map<int,int> > g;
vector<int> scc;
int its_dfs_1 = false;

void dfs( int nd ) {
    if( visited[nd] ) return;
    visited[nd] = true; 
    for( auto i : g[nd] ) {
        if( visited[i.first] ) continue;
        dfs( i.first );
    }
    
    if( its_dfs_1 ) st.push( nd );
    else cout << nd << " ";
}

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        int n, m, x, y;
        cin >> n >> m;
        for( int i=0; i<n; i++ ) {
            cin >> x >> y;
            g[x][y] = 1;
        }
        its_dfs_1 = true;
        
        for( int i=0; i<m; i++ ) {
            dfs(i);
        }
        
        map<int, map<int,int> > t_g;
        for( auto i : g )
            for( auto ix : i.second )
                t_g[ix.first][i.first] = 1;

        g = t_g;
        visited.clear();
        its_dfs_1 = false;
        while( !st.empty() ) {
            dfs( st.top() );
            cout << "\n";
            while( !st.empty() && visited[st.top()] ) st.pop();
        }
    }
}

        


