#include <stdio.h>
#include <math.h>

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		double r;
		scanf("%lf", &r);
		double pi = 2*acos(0.0);
		double ans = (4*r*r) - (pi*r*r) + pow(10, -9);
		printf("Case %d: %.2lf\n", i, ans);
	}
}