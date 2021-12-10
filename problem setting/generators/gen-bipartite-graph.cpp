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


const int testcases = 10000000;
const int N = 1000000;
const int ai = 1000000;


int vis[N];
map<int,map<int, int> > g;
void dfs( int node ) {
    if( vis[node] ) return;
    vis[node] = 1;
    for( auto i:g[node] ) {
        dfs( i.first );
    }
}

int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z, e;
    scanf("%d", &t);
    if( t > testcases ) {
        printf("wrong");
        return 1;
    }
    while(t--){
        scanf("%d %d", &n, &e);
        if( n >= N ) {
            printf("wrong");
            return 1;
        }
        for(int i=0; i<=n; i++) vis[i] = 0;
        if( n==1 ) continue;
        set<int> a;
        for(int i=0; i<e; i++) {
            scanf("%d %d", &x, &y);
            g[x][y] = 1;
            g[y][x] = 1;
            a.insert(x);
            a.insert(y);
        }

        dfs(x);

        for(auto i:a) {
            if( !vis[i] ) {
                printf("%d %d wrong\n", t, i);
                return 1;
            }
        } 

    }
    printf("OK");
    return 0;
}