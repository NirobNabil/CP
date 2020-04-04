#include <stdio.h>
#include <math.h>

int facts[70000][2];
int prime_facts(long long int n){
	int next=-1;
	while(n%2==0){
		n/=2;
		//printf("%lld,%d ", n,2);
	}
	for(int i=3; i<=ceil(sqrt(n)); i+=2){
		if(n%i==0){
			facts[++next][0]=i;
			facts[next][1]=0;
		}
		while(n%i==0){
			n/=i;
			//printf("inp %lld,%d,%d ", n,i,facts[next][1]);
			facts[next][1]++;
		}
	}
	//if n>2 even after dividing inside the above loop. the n has come to a prime number after diviiding 
	if(n>2) facts[++next][0]=n, facts[next][1]=1;// printf("%lld,%d ", n,n); 
	//printf("\n");
	facts[++next][0]=-1;
	return next;
}

int main(){
	int t,ix;
	scanf("%d", &t);
	for(ix=1; ix<=t; ix++){
		long long int n;
		scanf("%lld", &n);
		int fact_num = prime_facts(n);
		int ans=1;
		for(int i=0; i<fact_num; i++){
			ans *= facts[i][1]+1;
		}
		printf("Case %d: %d\n", ix, --ans);
	}
	return 0;
}