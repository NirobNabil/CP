#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	int queue[1000005];
	int q, n, s=0, e=0;
	while(t--){
		scanf("%d", &q);
		if(q==1) {
			scanf("%d", &n);
			queue[e++] = n;
		}else if(q==2) s = min(s+1,e);
		else if(q==3) {
			if(e-s>0) printf("%d\n", queue[s]	);
			else printf("Empty!\n");
		}
	}
}