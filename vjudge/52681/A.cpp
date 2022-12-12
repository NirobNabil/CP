
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

unordered_map<int, int> xx;
const int mx = 10e6+9;
int s[mx];

int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }

    vector<int> qq;
    for(int i=0; i<n; i++) {
        xx[a[i]] = 1;
    }
    for( auto i:xx ) {
        qq.push_back(i.X);
    }
    xx.clear();
    
    for( int i=0; i<qq.size(); i++ ) {
        int x = qq[i]*2;
        while( x < mx ) {
            s[x] = 1;
            x += qq[i];
        }
    }

    int count = 0;
    for( int i=0; i<n; i++ ) {
        if( s[a[i]] == 0 ) {
            xx[a[i]]++;
        }
    }


    for( auto i : xx ){
        if( i.Y == 1 ) count++;
    }

    printf("%d\n", count);
}

