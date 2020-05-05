#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		double ax, ay, bx, by, cx, cy, dx, dy;
		scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
		dx = ax+(cx-bx), dy=ay+(cy-by);
		double area = abs(((ax*by+bx*cy+cx*dy+dx*ay)-(ax*dy+dx*cy+cx*by+bx*ay))/2);
		printf("Case %d: %.f %.f %.f\n", i, dx, dy, area);
	}
}