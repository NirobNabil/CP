#include <stdio.h>

int main(){
	long long int n;
	while(scanf("%lld", &n) != EOF){
		long long int ans=n;
		if(n>7 && n<14){
      while(--n){
        ans*=n;
      }
  	  printf("%lld\n", ans);
		}else if(n<=7) printf("Underflow!\n");
		else if(n>=14) printf("Overflow!\n");
	}
	return 0;
}
