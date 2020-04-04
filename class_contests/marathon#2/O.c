#include <stdio.h>
#include <math.h>

int main(){
	int t;
	scanf("%d", &t);
	long long int n;
	int base;
	for(int ix=1; ix<=t; ix++){
		scanf("%lld %d", &n, &base);
		if(n==0 || n==1) printf("Case %d: 1\n", ix);
		else {
			double x = ceil(((n*log(n/M_E)/log(base)+(log(2*M_PI*n)/log(base))/2.0)));
			printf("Case %d: %.0f\n", ix, x);
		}
	}
	return 0;
}