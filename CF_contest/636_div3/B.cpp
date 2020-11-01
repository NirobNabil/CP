#include <stdio.h>

int main(){
	int t, n, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n==2 || (n/2)%2==1) printf("NO\n");
		else{
			printf("YES\n");
			for(i=1; i<=n/2; i++) printf("%d ", i*2);
			for(i=1; i<=n/4; i++) printf("%d ", i*2-1);
			for(i=n/2; i>n/4; i--) printf("%d ", i*2+1);
			printf("\n");
		}
	}
}