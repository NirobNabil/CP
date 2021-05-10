#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		ll n, k;
		scanf("%lld %lld", &n, &k);
	  printf("%lld\n", ( ( ( ((n+1)  * (n+2)) / 2) % 1000000007 ) * (k+1)) % 1000000007 );
	}
}