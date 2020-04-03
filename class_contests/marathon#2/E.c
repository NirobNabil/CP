#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++){
		int n,p,q;
		scanf("%d %d %d", &n, &p, &q);
		int eggs[n];
		for(int i=0; i<n; i++) scanf("%d", &eggs[i]);
		int weight=0, count=0;
		for(int i=0; count<p && weight<q && i<n; ((weight+eggs[i]>q)? i=n : (weight+=eggs[i], count++)), i++) printf("");
		printf("Case %d: %d\n", ix, count);
	}
}