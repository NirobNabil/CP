#include "bits/stdc++.h"
using namespace std;
#define ll long long int

#define alias if(h<=0 && n) { n--; h=d; printf("%.4lf %.4lf\n", x,y); }
#define rem(a,b) 
int main(){
	double a,d,k,x=0,y=0;
	int n;
	scanf("%lf %lf", &a, &d);
	double h=d;
	scanf("%d", &n);
	int  gg=10;
	int s=0,p,q;
	while(n && gg--){
		p = floor(round(d/a));
		q = d - p;
		s += (int)p;
		s %= 4;
		switch(s){
			case 1:
				if(a-x<q) q-=a-x;
				else d--, q = a-x-q;
				y=0;
				x = q;
		printf("%.4lf %.4lf\n", x,y);
			case 2:
				if(a-y<q) q-=a-y;
				else d--, q = a-y-q; 
				x = a;
				y = q;
		printf("%.4lf %.4lf\n", x,y);
			case 3: 
				if(x<q) q-=x;
				else d--, q = x-q;
				x = a-q;
				y = a;
		printf("%.4lf %.4lf\n", x,y);
			case 4: 
				if(y<q) q-=a-y;
				else d--, q = y-q;
				x = 0;
				y = a-q;
		printf("%.4lf %.4lf\n", x,y);
		}
		printf("%.4lf %.4lf\n", x,y);
	} 
}