#include <stdio.h>

long long int powers[31];

int main(){
	for(int i=1; i<31; i++){
		powers[i-1] = (1<<i);
		// printf("%lld\n", powers[i]);
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a=0, b=0, i=0;
		if(n==2){
			printf("2\n"); 
			continue;
		}
		a += powers[n-1];
		for(; i<n/2-1; i++) a+=powers[i];
		for(; i<n-1; i++) b+=powers[i]; 
		// printf("%d\n", a);
		printf("%d\n", a-b);
	}
}