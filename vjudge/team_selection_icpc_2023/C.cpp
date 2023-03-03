
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
    ll i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%lld %lld", &n, &q);
    vector<ll> a(n+2);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    a[n+1] = 100;
    vector< vector<ll> > v(n+2, vector<ll>(3,0));
    map<ll, ll> s;
    
    for(int i=1; i<=n+1; i++) {
        ll diff = a[i] - v[i-1][0], last;
        if( diff <= 1 ) {
            last = v[i-1][1];
        } else {
            last = a[i] - 1;
        }
        ll idx = v[i-1][2] + ( diff - 1 );
        debug(diff,last,idx);
        v[i] = { a[i], last, idx };
        s[idx] = v[i][1];
    }

    debug( v );
    debug( s );

    while(q--){
        scanf("%lld", &k);
        auto it = s.lower_bound(k);
        x = it->X;
        y = it->Y;
        printf("%lld\n", y - (x-k) );
    }
}


































