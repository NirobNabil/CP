#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	// scanf("%d", &t);
	ll n, m, k, i, res=0;
	scanf("%lld %lld %lld", &n, &k, &m);
	for(; k>0; k--) {
		ll tk=k+1, tn=n+2, r=1, i=k+2;
		bool d=false;
		while(--tn && --i>0){
			if(!d && tn%tk==0) r=(r*(tn/tk))%m, d=true;//, printf("*(%lld/%lld)", tn, tk);
			else r=(r*tn)%m; //, printf("*%lld", tn);
		}
		// printf("\n");
		res = (res+r)%m;
	} 
	printf("%lld\n", res);
}