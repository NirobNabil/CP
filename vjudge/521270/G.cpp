
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
int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%d %d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m+1));
    for(int i=0; i<n; i++) {
        for( int ix=0; ix<m; ix++) {
            scanf("%d", &a[i][ix]);
        }
    }

    vector<map<int,int>> ranges(n);

    for(int i=0; i<n; i++) {
        int g = 0;
        int prev = -1;
        for( int ix=0; ix<m+1; ix++) {
            if( a[i][ix] == 1 &&  g == 0  ) {
                ranges[i][ix] = -1;
                prev = ix;
                g = 1;
            } else if( a[i][ix] == 0 && g == 1) {
                ranges[i][prev] = ix;
                g = 0;
            }

        }
    }

//     for( int i=0; i<n; i++ ) {
//         for( auto range1 : ranges[i] ) {
//             for( int ix=i+1; ix<n; ix++ ) {
//                 for( auto range2 : ranges[ix] ) {
//                     
//                 }
//             }
//         }
//     }
    
    debug(a);
    debug(ranges);
}

