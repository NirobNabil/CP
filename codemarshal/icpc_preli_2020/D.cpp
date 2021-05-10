#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


ll M = 1000000007;
ll fact[10009], b[10009], nc2[10009];

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

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
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
    for(ll i=1; i<=a; i++) {
        ans = (ans * i) % m;
    }
    return ans;
}


ll ncr(ll n, ll r, ll m) {
    return bdiv(fact[n], (fact[n-r]) % m, m);
}


ll getbigs(ll i, vector<pair<ll, ll> > &a) {
	if(i == a.size()-1) {
		b[i] = 0;
		return b[i];
	}

	if(a[i+1].X > a[i].X) {
		b[i] = getbigs(i+1, a) +1;
	}else 
		b[i] = getbigs(i+1, a);
	
	return b[i];
}

ll getmax(ll ci, ll n, vector<pair<ll,ll> > &a) {
	ll mx = fact[n];
	for(ll i = ci; i<n && n-(i-ci)-3 >= 0; i++) {
		mx -= ( ( nc2[b[i]] * fact[n-(i-ci)-3]) % M );
		// printf("%lld\n", mx);
	}
	mx -= ( ( ( b[ci] * fact[n-2] ) % M ) * (ll)2 ) % M;
	// printf("%lld %lld\n", ci, mx);

	return mx;
}

int main(){
	ll i, ix, t, n, x, y, z;
	scanf("%lld", &t);
	fact[0] = 1;
	fact[1] = 1;
	for(ll i=2; i<=1009; i++) {
		fact[i] = (i * fact[i-1]) % M;
	} 
	nc2[0] = 0;
	nc2[1] = 0;
	for(ll i=2; i<=1009; i++) {
		nc2[i] = ncr(i, 2, M);
	}
	// printf("%lld\n", nc2[2]);
	for(ll tc=1; tc<=t; tc++) {
		scanf("%lld", &n);
		vector<pair<ll,ll> > a;
		for(ll i=0; i<n; i++) {
      scanf("%lld", &x);
			// cerr << "GG" << endl;
      a.push_back(make_pair(x,i));
    }
  	printf("Case %d:\n", tc);
    if(n == 1) {
    	printf("%d\n", 1);
    	continue;
    }
  	sort(a.A(), a.B());
  	getbigs(0, a);
  	// for(ll i=0; i<n; i++) {
  	// 	printf("%lld ", b[i]);
  	// }
  	vector<ll> ans(n);
  	for(ll i=0; i<n; i++)  {
	  	ans[a[i].Y] = getmax(i, n, a); 
  	}
  	for(ll i=0; i<n; i++) {
  		printf("%lld\n", ans[i]);
  	}
	}

	return 0;
}