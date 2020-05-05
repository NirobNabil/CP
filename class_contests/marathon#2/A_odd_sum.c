#include <stdio.h>

int dd(int n){
	return n*(n+1);
}

int main(){
	int t;
	scanf("%d", &t);
	int i=1;
	for(; i<=t; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		int total = dd(b)/2 - dd(a-1)/2 - dd(b/2) + dd((a-1)/2);
		printf("Case %d: %d\n", i, total);
	}
	return 0;
}