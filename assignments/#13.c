#include <stdio.h>

int called[101] = {0};

int fib(int n){
	called[n]++;
	if(n<=1) return n;
	return fib(n-1) + fib(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	int i;
	for(i=1; i<=n; i++) printf("%d %d\n", i, called[i]);
	return 0;
}