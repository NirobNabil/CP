#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int main(){
	long long x,y;
	while(scanf("%lld %lld", &x, &y) != EOF) printf("%lld\n", MAX(y,x)-MIN(y,x));
	return 0;
}