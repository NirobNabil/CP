#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if(n==1) printf("-1\n");
		else if(n>=2){
			int gg=n-1;
			printf("2");
			while(gg--) printf("3");
			printf("\n"); 
		}
	}
}