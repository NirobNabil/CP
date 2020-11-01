#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int granny[n];
		for(int i=0; i<n; i++) scanf("%d", &granny[i]);
		qsort(granny, n, sizeof(int), compare);
		int gg=0, i=n;
		while(--i>=0){
			if(granny[i] <= i+1) {
				printf("%d\n", i+2);
				gg=1;
				break;
			}
			if(i==0) printf("%d\n", 1);
		}
	}
}