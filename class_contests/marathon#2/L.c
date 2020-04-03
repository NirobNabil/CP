#include <stdio.h>
#include <math.h>
//#define M_PI 3.1415926535

int main(){
	int t;
	scanf("%d", &t);
	int ix=1;
	for(; ix<=t; ix++){
		double r1, r2, h, p;
		scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
		double r3 = ((r1-r2)/h)*p + r2;
		double vol = (1.0/3.0)*M_PI*p*(pow(r2,2)+r2*r3+pow(r3,2));
		printf("Case %d: %lf\n", ix, vol);
	}
	return 0;
}
