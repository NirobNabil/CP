#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	for(int ii=0; ii<t; ii++) {
		int n, m, r=0;
		char cmd[10];
		scanf("%d", &n);
		printf("Case %d:\n", ii+1);
		for(int i=0; i<n; i++) {
			scanf("%s", &cmd);
			if(!strcmp(cmd,"donate")) {
				scanf("%d", &m);
				r+=m;
			}else {
				printf("%d\n", r);
			}
		}
	}
}