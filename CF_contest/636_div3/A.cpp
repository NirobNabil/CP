#include <stdio.h>

long int powers[31];

int main(){
	powers[0]=1;
	for(int i=1; i<35; i++){
		powers[i] = powers[i-1] + (1<<i);
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i=1; i<35; i++){
			if(n%powers[i]==0){
				printf("%d\n", n/powers[i]); 
				break;
			}
		}
	}
}