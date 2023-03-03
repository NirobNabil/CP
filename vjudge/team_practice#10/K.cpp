#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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



ll fact[1000000];
ll bfact(ll a, ll m) {
    if(fact[a]) return fact[a];
    ll ans = 1;
    for(int i=1; i<=a; i++) {
        ans = (ans * i) % m;
        fact[i] = ans;
    }
    return ans;
}


ll ncr(ll n, ll r, ll m) {
    if(r > n) return 0;
    return bdiv(bfact(n, m), (bfact(r, m) * bfact(n-r, m)) % m, m);
}

int main(){
    ll i, ix, t, n, a, b, c, k, mc;
    bfact(100009, 1000000007);
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &k, &mc);
        ll m = 1000000007;

        if(k-mc < 2) {
            cout << 0 << endl;
            continue;
        } 

        // ll ans = (((a * b) % m) * ncr(c, mc, m)) % m;
        // ans = ( ans * ncr(a+b-2, k-mc-2, m) ) % m;
        ll ncr_c = ncr( c, mc, m);
        ll ans = (ncr(a+b, k-mc, m) * ncr_c) % m;
        // printf("%lld\n", ans);
        ans = (ans - (ncr(b, k-mc, m) * ncr_c)) % m;
        // printf("%lld\n", ans);
        ans = (ans - (ncr(a, k-mc, m) * ncr_c)) % m;
        // printf("%lld\n", ans);
        cout << (ans % m + m )%m << "\n";
    }
}