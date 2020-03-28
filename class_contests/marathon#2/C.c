#include <stdio.h>

int main(){
	long long int a,b,c,t;
	scanf("%lld", &t);
	int i=1;
	for(; i<=t; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("Case %d: ", i);
		if(a+b<=c || b+c<=a || c+a<=b || a<1 || b<1 || c<1) printf("Invalid\n");
		else if(a==b && b==c && c==a) printf("Equilateral\n");
		else if(a==b ^ b==c ^ c==a) printf("Isosceles\n");
		else printf("Scalene\n");
	}
	return 0;
}
