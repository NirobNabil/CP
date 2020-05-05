#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int gg[n];
		for(int i=0; i<n; i++) scanf("%d", &gg[i]);
		//printf("%d\n", n*7+1);
		int miss=0;
		int lastMiss=INT_MAX;
		int i=0;
		// printf("%d\n", gg[0]);
		for(; i<n-1; i++){
			if(gg[i]>lastMiss || gg[i+1]-gg[i]>1){
				miss=1;
				break;
			}
			if(gg[i]>gg[i+1]) lastMiss=gg[i];
		}
		if(miss==0) printf("Yes\n");
		else printf("No\n");
	}
}