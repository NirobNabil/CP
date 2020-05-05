#include <stdio.h>
#include <math.h>
#define g 0.00000001
#define CEIL(a,b) (a/b+((a%b)?1:0))

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++){
		int m,n;
		scanf("%d %d", &m, &n);
		printf("Case %d: ",ix);
		if(m==1 || n==1) printf("%d\n", (m==1)?n:m);
		else if(m==2 || n==2){
			int gg = (m==2)?n:m;
			printf("%d\n", (gg/4)*4 + (((gg%4)/2)?4:(gg%2)*2));
		}
		else printf("%d\n", CEIL(m,2)*CEIL(n,2)+(m/2)*(n/2));
	}
}