#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll unsigned long long int

ll fact(ll n, ll k){
	ll c=1;
	for(ll i=0, j=n; i<k; i++, j--) {
		c *= j;
	}
	return c;
}

ll printNcR(ll n, ll r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
    if (r != 0) { 
        while ( r ) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m;   
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    // cout << p << endl; 
  return p;
} 

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		ll n, k;
		scanf("%lld %lld", &n, &k);
		if(k>n){
    	printf("Case %d: %ld\n", ix, 0);
    	continue;
		}else if(k==n){
			printf("Case %d: %ld\n", ix, fact(n,k));
    	continue;	
		}
		// printf("%d %d\n", n, k);
    printf("Case %d: %ld\n", ix, fact(n, k)*printNcR(n,n-k));
	}
}

//fact(n, k) * (fact(n,n-k)/fact(n-k, n-k))