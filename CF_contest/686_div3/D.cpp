#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MAX(a,b) ((a>b)?a:b)

vector<long long> primes;
// ll primes[max+1] = {0};
// ll nums[max+1] = {0};
int generate_primes(ll n){
		ll nums[n+9] = {0};
    int i=3, ix;
    for(; i<=n; i+=2){
        ix=i+i;
        if(!nums[i]) for(; ix<=n; ix+=i) nums[ix] = 1; 
    }
    primes.push_back(2);
    i=3;
    for(; i<=n; i+=2){
        if(!nums[i]) primes.push_back(i);
    }
    return 0;
}

unordered_map<ll,ll> fact;
int trial_division4(ll n) {
		fact.clear();
    for (ll d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            fact[d]++;
            n /= d;
        }
    }
    if (n > 1)
        fact[n]++;
    return 0;
}

int main(){
	ll i, ix, t, n, a[S1];
	scanf("%lld", &t);
	generate_primes(200000);
	while(t--){
		scanf("%lld", &n);
		trial_division4(n);
		ll m = 0, n;
		for(auto i:fact)  {
			if(i.Y>m) m = max(m, i.Y), n=i.X;
		}
		printf("%lld\n", m);
		ll gg=n;
		fact[n]--;
		for(auto i:fact) {
			if(i.X!=n) {
				while(i.Y--) gg *= i.X;
			}
		} 
		while(fact[n]--) printf("%lld ", n);
		printf("%lld ", gg);
		printf("\n");
		// printf("t- %lld n-%lld\n", t, n);
	}
	return 0;
}