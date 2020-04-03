#include <stdio.h>
#include <math.h>

int a[10000];
int b[10000];

int main(){
	int t;
	scanf("%d", &t);
	int ix=1;
	for(; ix<=t; ix++){
		int c,p,q,l,i=1, count=0, next=0;
		scanf("%d %d", &p, &l);
		p -= l; 
		for(; i*i<=p; i++){
			
			if(p%i==0){
				a[next]=i;
				if(i*i != p) b[next]=p/i;
				next++;
			};
		}
		printf("Case %d: ", ix);
		int ir, imp=1;
		for(ir=0; ir<next; ir++) if(a[ir]>l) printf("%d ", a[ir]), imp=0;
		for(ir=(((i-1)*(i-1)==p)?next-2:next-1); ir>=0; ir--) if(b[ir]>l) printf("%d ", b[ir]), imp=0;
		if(imp) printf("impossible");
		printf("\n");
	}
}