#define CEIL(a,b) ( (a)%(b) ? (a)/(b)+1 : (a)/(b) )


long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


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


ll bfact(ll a, ll m) {
    ll ans = 1;
    for(int i=1; i<=a; i++) {
        ans = (ans * i) % m;
    }
    return ans;
}


ll ncr(ll n, ll r, ll m) {
    return bdiv(bfact(n, m), (bfact(r, m) * bfact(n-r, m)) % m, m);
}


class combi
{
public:
    ll mod;
    vector <ll> factorial,inv;
    void init(ll n,ll m = ll(1e9+7)){
        mod = m;
        inv.reserve(n+1);
        factorial.reserve(n+1);
        factorial[0] = 1;
        inv[0] = inv_mod(1,mod);
        for(int i=1;i<=n;i++){
            factorial[i] = (factorial[i-1]*i)%mod;
            inv[i] = inv_mod(factorial[i],mod);
        }
    }
    ll C(ll n,ll r){
        if(r>n) return 0;
        ll ans = 1;
        ans = ans*factorial[n]%mod;
        ans = ans*inv[r]%mod;
        ans = ans*inv[n-r]%mod;
        return ans;
    }
} com;


//diophantine eq

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

// combinatorics lelbaba
const int N = 2e5+5;
const int mod = 1e9+7;

namespace com{
    array <int, N+1> fact, inv, inv_fact;
    void init(){
        fact[0] = inv_fact[0] = 1;
        for(int i = 1; i <= N; i++){
            inv[i] = i == 1 ? 1 : (ll) inv[i - mod%i] * (mod/i + 1) % mod;
            fact[i] = (ll) fact[i-1] * i % mod;
            inv_fact[i] = (ll) inv_fact[i-1] * inv[i] % mod;
        }
    }
    int C(int n,int r){
        if(fact[0] != 1) init();
        return (r < 0 or r > n) ? 0 : (ll) fact[n]*inv_fact[r] % mod * inv_fact[n-r] % mod;
    }
}
