// #include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int a[int(10e5)], b[int(10e5)];

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}	
		b[n-1]=(a[n-1]==1)?1:0;
		// printf("%d ", b[n-1]);
		for(int i=n-2; i>=0; i--) {
			if(a[i]==1) b[i]=b[i+1]+1;
			else b[i]=0;
			// printf("%d ", b[i]);
		}
		// printf("\n");
		int cp=0;
		for(int i=0; i<n;) {
			if(i==n-1) {
				cp=!cp;
				i++;
			}else if(b[i+1]>0 && b[i]==0){
				i+= b[i+1]+1; 
				if(i==n) cp=!cp;
				// printf("gg %d %d\n", b[i+1], n-1-i);
				// printf("gg %d %d\n", i, cp);
			}else if(b[i]==0){
				// printf("xd %d %d\n", i, cp);
				i++;
			}else{
				i++;
				cp=!cp;
			}
		}
		if(cp==0) printf("Second\n");
		else printf("First\n"); 
	}
}