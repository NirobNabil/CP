#include <stdio.h>
#include <math.h>

long long int a[10000];
long long int b[10000];

int main(){
	int t;
	scanf("%d", &t);
	int ix=1;
	for(; ix<=t; ix++){
		long long int c,p,q,l,i=1, count=0, next=0;
		scanf("%lld %lld", &p, &l);
		p -= l; 
		if(p==0 && l==0){ printf("Case %d: 1\n", ix); continue; }
		for(; i*i<=p; i++){
			if(p%i==0){
				a[next]=i;
				if(i*i != p) b[next]=p/i;
				next++;
			};
		}
		printf("Case %d: ", ix);
		long long int ir, imp=1;
		for(ir=0; ir<next; ir++){
			if(a[ir]>l){
				printf("%lld", a[ir]);
				imp=0;
				if(ir+1==next && a[ir]*a[ir]==p && next-2<0) printf("");
				else printf(" ");
			}
		}
		for(ir=(((i-1)*(i-1)==p)?next-2:next-1); ir>=0; ir--){
			if(b[ir]>l){
				printf("%lld", b[ir]);
				imp=0;
				if(ir!=0) printf(" ");
			}
		}
		if(imp) printf("impossible");
		printf("\n");
	}
}