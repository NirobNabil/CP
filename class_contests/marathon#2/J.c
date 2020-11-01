#include <stdio.h>
#include <math.h>
long long int CEIL__(long long int a,int b){
	return (a%b)?a/b+1:a/b;
}

int main(){
	long long int n;
	while(scanf("%lld", &n) && n>=0){
		printf("%lld\n", CEIL__((n*(n+1)),2)+1);
	}
	return 0;
}