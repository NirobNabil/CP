#include "bits/stdc++.h"
using namespace std;
#define ll long long int
const ll mod=1000000007;
 
ll power(ll a, ll b) {
	ll r=1;
	for(ll i=0; i<b; i++) {
		r = (r*a)%mod;
	}
	return r;
}
 
int main(){
	ll n, r;
	scanf("%lld", &n);
	r=0;
	r += power(10,n);
	r -= 2*power(9,n);
	r += power(8,n);
	r %= mod;
	r = (r+mod)%mod;
	printf("%lld\n", r);
}