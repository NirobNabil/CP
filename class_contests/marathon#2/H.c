#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d", &t);
	int ix=1;
	for(; ix<=t; ix++){
		int a,b,ans=0;
		scanf("%d %d", &a, &b);
		int tempa = a - a%3;
		int tempb = b - b%3;
		ans = ((tempb-tempa)/3)*2;
		if(a%3==0) ans+=1;
		if(b%3==2) ans+=1;  
		printf("Case %d: %d\n", ix, ans);
	}
}

48499473
