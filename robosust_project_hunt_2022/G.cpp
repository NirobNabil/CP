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

const ll MOD = 1000000009;

#define CEIL(a,b) ( (a)%(b) ? (a)/(b)+1 : (a)/(b) )


ll bpow(ll a, ll b, ll m) {
    a %= m;
    ll r = 1;
    while( b>0 ) {
        if(b & 1) r = (r * a) % m;
        a = (a * a)%m;
        b >>= 1;
    }
    return r;
}


ll bdiv(ll a, ll b, ll m) {
    // https://www.geeksforgeeks.org/fermats-little-theorem/
    return (a%m) * bpow(b, m-2, m) % m;
}


ll fact[10009];
ll bfact(ll a, ll m) {
    // ll ans = 1;
    // for(int i=1; i<=a; i++) {
    //     ans = (ans * i) % m;
    // }
    return fact[a];
}


ll ncr(ll n, ll r, ll m) {
    return bdiv(bfact(n, m), (bfact(r, m) * bfact(n-r, m)) % m, m);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fact[0] = 1;
	for(int i=1; i<10009; i++) {
		fact[i] = (fact[i-1] * (ll)i) % MOD;
	} 

	vector<int> dp(5009);
	for(int i=2; i<=5000; i++) {
		// for(int ix=1; ix<=i; ix++) {
		// 	// debug(ix-1, i-ix);
		// 	dp[i] += (dp[ix-1] * dp[i-ix]) % MOD;
		// } 
		// debug(bfact(2*n, MOD) / ( bfact(n+1, MOD) * bfact(n, MOD) ));
		dp[i] = bdiv( bfact(2*i, MOD), ( bfact(i+1, MOD) * bfact(i, MOD) ), MOD );
		// debug(i, dp[i]);
	}

	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		dp[0] = 1;
		dp[1] = 1;
    	

    	ll ans = 0;
    	for(int i=1; i<=n; i++) {
    		ans += (dp[i]*ncr(n, i, MOD)) % MOD;
    		ans %= MOD;
    	}

    	cout << ans << "\n";
	}
}
