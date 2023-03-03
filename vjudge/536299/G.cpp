
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

int dp[10000][5];
vector<int> coins = {50, 25, 10, 5, 1};

int chk( int cap, int idx ) {
    if( cap < 0 ) cout << "ERROR" << endl;
    if( cap == 0 ) return 1; 
    if( dp[cap][idx] != 0 ) return dp[cap][idx];
    if( idx == 4 ) return 1;
    //debug(cap, idx);
    int n = 0;
    while( n <= (cap / coins[idx]) ) {
        int y = cap - n*coins[idx];
        dp[cap][idx] += chk( cap - n*coins[idx], idx+1 );
        //debug(n, idx, y, dp[cap][idx]);
        n++;
    } 
    //debug(cap, dp[cap][idx]);
    return dp[cap][idx];
}


int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    memset(dp, 0, sizeof(dp));
    while(cin >> n){
        printf("%d\n", chk(n, 0));
    }
}

