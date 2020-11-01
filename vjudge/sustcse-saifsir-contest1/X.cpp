#include <iostream>
#include <climits>
using namespace std;
#define ll long long int

int storage[14]={0};

int main(){
	int n;
	bool gg;
	int ix, ng, vg;
	while(1){
		gg=false;
		scanf("%d", &n);
		if(n==0) {
			return 0;
		}else if(n==1){
			printf("2\n");
			continue;
		}else if(storage[n]!=0){
			printf("%d\n", storage[n]);
			continue;
		}
		for(ix=n+1; ix<INT_MAX && !gg; ix++) {
			ng=n*2;	
			gg=true;
			for(vg=ix%ng; ng>n && gg; ng--) {
				if(vg<=n && vg!=0) gg=false;
				// printf("%d- %d- %d\n", ix, ng, vg);
				vg = (ix - (ng-(vg?vg:ng)) )%(ng-1);
			}
			if(gg) {
				storage[n] = ix;
				printf("%d\n", ix);
			}
			// while((++ix%(n*2))<=n) continue;
		}
	}
}