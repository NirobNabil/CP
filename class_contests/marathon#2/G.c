#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a>b)?b:a)

char names[100][21];
int dims[100][3];
int vols[100];
int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++){
		int n, min=999999999, max=0, minI, maxI;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%s %d %d %d", names[i], &dims[i][0], &dims[i][1], &dims[i][2]), vols[i]=dims[i][0]*dims[i][1]*dims[i][2]; 
		for(int i=0; i<n; i++){
			min = MIN(min, vols[i]);
			max = MAX(max, vols[i]);
			if(min == vols[i]) minI=i;
			if(max == vols[i]) maxI=i;
		}
		//printf("%s\n", names[0][0]);
		printf("Case %d: ", ix);
		if(min==max) printf("no thief\n");
		else printf("%s took chocolate from %s\n", names[maxI], names[minI]);
	}
}