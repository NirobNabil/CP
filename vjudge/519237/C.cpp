
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


map<int, map<int,ll> > warshall( map<int,map<int, ll> > &g, set<int> &nodes ) {
    
    map<int, map<int,ll> > d;

    for( auto i : nodes ) 
        for( auto j : nodes )
            if( i == j ) d[i][j] = 0;
            else if ( g[i].find(j) == g[i].end() ) 
                d[i][j] = INT_MAX;
            else d[i][j] = g[i][j];


    for( auto k : nodes ) {
        for( auto i : nodes ) {
            for( auto j : nodes ) {
                if( i == j ) continue;
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
            }
        }
    }

    return d;

}


int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;

    int tc = 1;
    n = 100;
    
    while( 1 ) {

        map<int, map<int,ll> > g;
        set<int> nodes;

        
        cin >> x >> y;
        if( x == 0 && y == 0 ) break;

        do {            
            g[x][y] = 1;
            nodes.insert(x);
            nodes.insert(y);
        } while( cin >> x >> y && !( x==0 && y==0 ) );

        map<int, map<int,ll> > d = warshall( g, nodes );

        ll ans = 0;
        for( auto i : d ) {
            for ( auto j : i.Y ) {
                ans += j.Y;
            }
        }

        cout << "Case " << tc << ": average length between pages = ";
        cout << setprecision(3) << fixed << (float)ans / (float)(nodes.size()*(nodes.size()-1));
        cout << " clicks\n";
 
        tc++;

    }


}



// 1 2 2 4 1 3 3 1 4 3 0 0
// 1 2 1 4 4 2 2 7 7 1 0 0
// 0 0

