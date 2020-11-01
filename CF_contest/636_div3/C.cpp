#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) ((a>b)?a:b)

int main(){
	int t, n, i;
	scanf("%d", &t);
	while(t--){
		long long int total=0, xd;
		scanf("%d", &n);
		int in[n];
		for(i=0; i<n; i++) scanf("%d", &in[i]);
		for(i=0; i<n;){
			if(in[i]>=0){
				xd=-1000000000;
				for(; i<n; i++){
					if(in[i]<0){
						total+=xd;
						break;
					}
					xd = MAX(xd, in[i]);
				}
			}else{
				xd=-1000000000;
				for(; i<n; i++){
					if(in[i]>=0){
						total+=xd;
						break;
					}
					xd = MAX(xd, in[i]);
				}
			}
		}	
		total += xd;
		printf("%lld\n", total);
	}
}