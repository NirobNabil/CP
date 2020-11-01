#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define I(i) ((i<n) ? i : n-i%n-2)
#define MAX 205

int n;
int a[MAX][MAX], b[MAX][MAX];

int down(int i, int ii) {
	if(ii>I(i) || ii<0) return 0;
	else if(i== (2*n)-1) return a[i][ii];
	else if(b[i][ii]!=-1) return b[i][ii];
	else {
		// printf("%d, %d - %d, %d - %d, %d - %d\n", i, ii, i+1, ii+(i+1!=I(i+1)?0:1), i+1, ii-(i+1!=I(i+1)?1:0), a[i][ii]);
		b[i][ii] = max(down(i+1, ii+(i+1!=I(i+1)?0:1)), down(i+1, ii-(i+1!=I(i+1)?1:0))) + a[i][ii];
		return b[i][ii];
	}
}

int main(){
	int t, j;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		scanf("%d", &n);
		for(int i=0; i<n*2; i++) {
			for(int ii=0; ii<=I(i); ii++) {
				scanf("%d", &j);
				a[i][ii] = j;
				b[i][ii] = -1;
			}
		}
		if(n==1) {
			printf("Case %d: %d\n", ix, a[0][0]);
			continue;
		}else printf("Case %d: %d\n", ix, down(0,0));
	}
}