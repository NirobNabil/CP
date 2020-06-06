#include <stdio.h>
#include <stdlib.h>
using namespace std;

int compare (const void * a, const void * b){
  return -( *(int*)a - *(int*)b );
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, n_actual;
		scanf("%d", &n);
		n_actual = n;
		int nums[n];
		for(int i=0; i<n; i++) scanf("%d", &nums[i]);
		qsort(nums, n, sizeof(int), compare);
		if(n%2==1) n--;
		for(int i=n/2-1; i>=0; i--){
			printf("%d %d ", nums[n-i-1], nums[i]);	
		}
		if(n_actual%2==1) printf("%d ", nums[n]);
		printf("\n");
	}
}