#include "bits/stdc++.h"
using namespace std;
#define ll long long int

double get_dist(double x1, double y1, double x2, double y2){
	return sqrt(pow((x1-x2),2.0) + pow((y1-y2),2.0));
}

int main(){
	int a;
	double b, x1,y1,x2,y2,r=0, bx, by;
	scanf("%d %lf %lf %lf", &a, &b, &x2, &y2);
	bx = x2, by = y2;
	for(int i=0; i<a; i++) {
		x1=x2; y1=y2;
		scanf("%lf %lf", &x2, &y2);
		// printf("%lf %lf %lf\n", r, x2, y2);
		r += get_dist(x1,y1,x2,y2); 
	}
	r += get_dist(x2,y2,bx,by);
	printf("%.2lf\n", r + 2*3.1415926535*b);
}