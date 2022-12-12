
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


vector<string> kahn( map<string, string > &g, int n ) {

    string st;
    map<string,int> in_deg;
    vector<string> ans;

    for( auto i : g ) {
        in_deg[i.X] = in_deg[i.X];
        in_deg[i.Y]++;
    }

    for( auto i : in_deg ) 
        if( i.Y == 0 ) 
            st = i.X;

    while( 1 ) {
        ans.push_back(st);
        if( ans.size() == n ) break;
        st = g[st];
    }

    return ans;
}


int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    
    cin >> t;

    for( int tc=1; tc<=t; tc++ ) {

        cin >> n;

        map<string, string> g;
        string s1, s2; 

        for( int i=1; i<n; i++ ) {
            cin >> s1 >> s2;
            g[s1] = s2;
        }

        vector<string> ans = kahn(g, n);

        cout << "Scenario #" << tc << ":\n";
        for( auto i : ans ) cout << i << "\n";
        cout << "\n";
    }


}


// 5 4
// 3 2 1 5
// 2 2 5 3
// 4 1 3
// 5 1 1

