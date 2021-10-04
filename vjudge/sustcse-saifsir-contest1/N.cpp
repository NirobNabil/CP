#include "bits/stdc++.h"
using namespace std;
#define ll long long int

ll fact(ll &x){
	ll r=x;
	while(--x){
		r*=x;
	}
	return r;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll g;
		scanf("%lld", &g);
		printf("%lld\n", g==0?1:fact(g));
	}
}