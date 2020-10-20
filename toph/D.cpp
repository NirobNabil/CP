#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		double x1, y1, x2, y2,x3, y3;
		double d1, d2, d3, v;
		scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
		if(x1==0.0) d1 = acos(0);
		else d1 = atan(y1/x1);
		if(x2==0.0) d2 = acos(0);
		else d2 = atan(y2/x2);
		printf("%f %f\n", d1, d2);
		d3 = d1+d2;
		x3 = x1+x2;
		y3 = y1+y2;
		v = sqrt(x1*x1 + y1*y1) + sqrt(x2*x2 + y2*y2);
		printf("%f %f\n", v*cos(d3), v*sin(d3));
	}
}