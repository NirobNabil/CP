#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	int ix=1;
	for(;ix<=t; ix++){
		long long int n, i=9;
		scanf("%lld", &n);
		printf("Case %d:", ix);
		for(; i>=0; i--){
			if((n-i)%9==0) printf(" %lld", ((n-i)/9)*10+i);
		}
		printf("\n");
	}
	return 0;
}