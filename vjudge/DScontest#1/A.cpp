#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	int stack[1000005];
	int q, n, i=0;
	while(t--){
		scanf("%d", &q);
		if(q==1) {
			scanf("%d", &n);
			stack[i++] = n;
		}else if(q==2) i = max(i-1,0);
		else if(q==3) {
			if(i-1>=0) 
				printf("%d\n", stack[i-1]	);
			else printf("Empty!\n");
		}
	}
}