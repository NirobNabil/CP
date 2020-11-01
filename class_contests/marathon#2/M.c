#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a>b)?b:a)

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++){
		int n;
		scanf("%d", &n);
		int cubes[n][2][3];
		int mins[n][3], maxs[n][3];
		for(int i1=0; i1<n; i1++){
			for(int i2=0; i2<3; i2++) scanf("%d", &cubes[i1][0][i2]);
			for(int i2=0; i2<3; i2++) scanf("%d", &cubes[i1][1][i2]);
			// for(int ia=0; ia<2; ia++){
			// 	for(int ib=0; ib<3; ib++){
			// 		for(int ic=0; ic<4; ic++) cubes[i1][sides[ia][ib][ic]][ib] = cubes[i1][ia][ib];
			// 	}
			// }
		}
		//printf("%d\n", cubes[0][6][0]);
		for(int i1=0; i1<n; i1++){
			//for(int i2=0; i2<7; i2++){
				for(int i3=0; i3<3; i3++){
					mins[i1][i3] = MIN(cubes[i1][0][i3], cubes[i1][1][i3]);
					maxs[i1][i3] = MAX(cubes[i1][0][i3], cubes[i1][1][i3]);
				}
			//}
		}
		int max[3]={999999999,999999999,999999999}, min[3]={0,0,0};
		for(int i1=0; i1<n; i1++){
			for(int i2=0; i2<3; i2++) min[i2] = MAX(mins[i1][i2], min[i2]), max[i2] = MIN(maxs[i1][i2], max[i2]);
		}
		//printf("%d %d %d %d %d %d\n", min[0], min[1], min[2], max[0], max[1], max[2]);
		int zero=0;
		for(int i=0; i<3; i++) if(max[i]<min[i]) zero=1;
		printf("Case %d: ", ix);
		if(zero) printf("0\n");
		else printf("%d\n", (max[0]-min[0])*(max[1]-min[1])*(max[2]-min[2]));

	}
	return 0;
}