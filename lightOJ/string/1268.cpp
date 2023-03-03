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

#define ull unsigned long long
const ull  MOD = UINT_MAX;  

ull binpow(ull a, ull b) {
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ull total;
vector<ull> dp;
ull chk(int n) {
	if(dp[n]) return dp[n];
    
}


int main(){
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	int i, ix, t, m, k, gg, y, z;
	cin >> t;
	for(int it=1; it<=t; it++) {
		string x, s;
		ull n;
		cin >> n >> x >> s;
		ull xl = x.length();
		ull sl = s.length();
		total = binpow(xl, n);
		dp.resize(n);
		for(int i=0; i<n - sl+1; i++) {
			total -= chk(n - i - sl);
		}
		cout << "Case " << it << ": " <<  - (binpow(xl, n-sl)*(n-sl+1))%MOD << "\n";
	}
}

