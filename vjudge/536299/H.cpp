
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

vector<int> v, s, dp;
int n, a, b;

int chk( int i, int p ) {
    if( i == n ) return 0; 
    if( p < v[i] && dp[i] != -1 ) return dp[i];
    for( int i=i, a=0; i<n; i++ ) {
        //debug(v[i], i, p);
        a = max(a, chk(i, p));
    };

    if( i == n ) return 0;
 
    b = chk(i+1, v[i]) + 1;

    if( b > a ) {
        s[i] = 1;
    } else s[i] = 0;
    
    return dp[i] = max(a,b);
}

int lis(  ) {
    for( int i=n-2; i>=0; i-- ) {
        for( int ix=i+1; ix<n; ix++ ) {
           if( v[ix] > v[i] ) {
               if( dp[ix]+1 > dp[i] ) {
                    s[i] = ix;
               } 
               dp[i] = max( dp[ix]+1, dp[i] );
           }
        }
    }

    int mx = 0;
    for( int i=0; i<n; i++ ) {
        if( dp[i] > dp[mx] ) mx = i;
    }

    return mx;
}


int main(){
    int i, ix, t, m, k, p, q, gg, x, y, z;
    
    while(scanf("%d", &i) != EOF){
        v.push_back(i);
    }
    n = v.size();
    
    auto st = std::chrono::high_resolution_clock::now();

    s.resize(n+1);
    dp.resize(n+1);

    cout << "g " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - st).count() << "\n";

    
    fill(s.A(), s.B(), n);
    fill(dp.A(), dp.B(), 1);
    cout << "g " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - st).count() << "\n";
    int start = lis();
    cout << "g " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - st).count() << "\n";
    printf("%d\n-\n", dp[start]);
    for( int i=start; i<n;  ) {
        printf("%d\n", v[i]);
        i = s[i];
    }
    cout << "g " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - st).count() << "\n";
}

