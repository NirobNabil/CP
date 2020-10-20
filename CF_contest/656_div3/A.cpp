#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, x, y, z, xd, a,b,c;
	scanf("%d", &t);
	while(t--){
		xd=0;
		scanf("%d %d %d", &x, &y, &z);
		for(int i=0; i<2; i++) {
			if(i==0) a=x; else a=y;
			for(int ix=0; ix<2; ix++){
				if(ix==0) b=x; else b=z;
				for(int iy=0; iy<2; iy++){
					if(iy==0) c=y; else c=z;
					if(x==max(a,b) && y==max(a,c) && z==max(b,c)) {
						printf("YES\n%d %d %d\n", a, b, c);
						ix=2; iy=2; i=2; xd=1; 
					}
				} 
			} 
		}
		if(!xd) printf("NO\n");
	}
}