
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long int
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
#define S1 5000009
// void __print(int x) {cerr << x;}
// void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
// void __print(unsigned x) {cerr << x;}
// void __print(unsigned long x) {cerr << x;}
// void __print(unsigned long long x) {cerr << x;}
// void __print(float x) {cerr << x;}
// void __print(double x) {cerr << x;}
// void __print(long double x) {cerr << x;}
// void __print(char x) {cerr << '\'' << x << '\'';}
// void __print(const char *x) {cerr << '\"' << x << '\"';}
// void __print(const string &x) {cerr << '\"' << x << '\"';}
// void __print(bool x) {cerr << (x ? "true" : "false");}
// template<typename T, typename V>
// void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
// template<typename T>
// void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
// void _print() {cerr << "]\n";}
// template <typename T, typename... V>
// void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
// #ifdef MONKE
// #define debug(x...) cerr << "[" << #x << "] = [", _print(x)
// #else
// #define debug(x...)
// #endif

int phi[S1];

void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    
    for( int i = 1; i<=n; i++ ) phi[i] *= phi[i];
    for( int i = 2; i<=n; i++ ) phi[i] += phi[i-1];
}

int32_t main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%llu", &t);
    phi_1_to_n(S1-1);
    for( int tt=1; tt<=t; tt++ ){
        scanf("%llu %llu", &x, &y);
        printf("Case %llu: %llu\n", tt, phi[y] - phi[x-1]);
    }
}

