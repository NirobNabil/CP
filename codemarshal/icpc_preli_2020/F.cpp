
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


#define MAX(a,b) ((a>b)?a:b)
#define max 10000000

int primes[max+1] = {0};
char nums[max+1] = {0};
void generate_primes(){
    int i=3, ix;
    for(; i<=max; i+=2){
        ix=i+i;
        if(!nums[i]) for(; ix<=max; ix+=i) nums[ix] = 1; 
    }
    int next = 1;
    primes[0] = 2;
    i=3;
    for(; i<=max; i+=2){
        if(!nums[i]) primes[next]=i, next++;
    }
    primes[next] = -1;
}

map<ll, int> occurences;
void prime_factors(vector<ll> &primes_facts, ll n){
    int i=0;
    occurences.clear();
    for(; i<max+1 && primes[i]!=-1 && n>1; i++){
        while(n%primes[i] == 0 && n>1){
            occurences[primes[i]]++;
            n /= primes[i];
        }
    }
    for( auto i:occurences ) if( i.Y > 0 ) primes_facts.push_back(i.X);
}

ll ans = 0;
ll i, ix, t, n, m, k, p, q, gg, x, y, z, a, b;
void bitmask(vector<ll> &primes) {

    int parity = -1;
    for( int mask=1; mask<(1<<primes.size()); mask++ ) {
        parity = 0;
        ll g = 1;
        for( int i=0; i<primes.size(); i++ ) 
            if( (mask & (1<<i)) > 0 ) g *= primes[i], parity++;
        ll cur = (b+m)/g - (b-1)/g;
        if( parity%2 ) ans -= cur;
        else ans += cur;
        debug(ans, mask, g);
    }

}

int main(){
    scanf("%lld", &t);
    generate_primes();
    for( int tc=1; tc<=t; tc++){
        scanf("%lld %lld %lld", &a, &b, &m);
        if( a > b ) swap(a,b);
        ans = m+1;

        ll d = b - a;
        vector<ll> primes_facts;
        prime_factors( primes_facts, d );

        debug(primes_facts);
        bitmask(primes_facts);

        debug(ans);

        cout << "Case " << tc << ": " << ans << "\n";
    }
    
}

