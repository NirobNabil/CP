#include <stdio.h>
#include <math.h>
#include <string.h>

int facts[101];
int factorial_prime_facts(int n){
	int total=0;
	for(int tempN=n; n>0; tempN=--n){
		//printf("gg\n");
		int xd = ceil(sqrt(tempN));
		// printf("sqrt %d\n", xd);
		for(int i=2; i<=xd; i++){
			//printf("ab %d %d %d\n", n, tempN, i);
			while(tempN%i==0){
				//printf("%d %d %d - ", n, tempN, i);
				tempN/=i;
				facts[i]++;
				//printf("%d %d\n", i, facts[i]);
			}
		}
		if(tempN>2) facts[tempN]++;	
	}
	for(int i=0; i<=100; i++) if(facts[i]) total++;
	return total;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++){
		memset(facts, 0, sizeof(facts));
		long long int n;
		scanf("%d", &n);
		int gg = factorial_prime_facts(n);
		//printf("%d\n", gg);
		printf("Case %d: %d =", ix, n);
		for(int i=1; i<=100; i++){
			if(facts[i]){
				gg--;
				printf(" %d (%d)", i, facts[i]);
				if(gg) printf(" *");
			}
		}
		printf("\n");
	}
}