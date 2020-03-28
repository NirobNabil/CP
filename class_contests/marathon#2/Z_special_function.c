#include <stdio.h>

int main(){
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", (n%2==0)?n/2:n/2-n);
}