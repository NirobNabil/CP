#include <stdio.h>
#include <math.h>
//#define M_PI 3.1415926535

int main()
{
	int t;
	scanf("%d", &t);
	int ix;
	for(ix=1; ix<=t; ix++){
		double R, r;
	    int n;
	    scanf("%lf %d", &R, &n);
	    r = R/(1.0+(1/sin((2.0*M_PI)/(n*2.0))));
	    printf("Case %d: %.6lf\n", ix, r);
	}
    return 0;
}