#include "bits/stdc++.h"
using namespace std;
 
int main(){
	int n;
	scanf("%d", &n);
	int senior[n];
	for(int i=0; i<n; i++) scanf("%d", &senior[i]);	
	int maxChain=0, c, chain;
	for(int i=0; i<n; i++) {
		c=senior[i], chain=1;
		while(c!=-1) c=senior[c-1], chain++;
		maxChain = max(chain, maxChain);
	}
	printf("%d\n", maxChain);
}