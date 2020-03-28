#include <bits/stdc++.h>

using namespace std;

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int binary_search(const int * arr, int start, int end, const int val){
	int mid = (end+start)/2;
	//printf("mid %d %d %d = %d, %d\n", start, end, mid, arr[mid], val);
	if(arr[mid]<=val && arr[mid+1]>=val){
		if(arr[mid]==val && arr[mid+1]>=val){
			if(mid == start || mid+1 == end) return -1;
			else return binary_search(arr, start, mid, val);
		}
		else return mid+1;
		//else if(arr[mid+1]==val) return mid;
	}else if((mid+1==end && arr[mid+1]<val) || (mid==start && arr[mid]>val)){
		return -1;
	}else{
		return (arr[mid]<val)?binary_search(arr, mid, end, val) : binary_search(arr, start, mid, val);
	}	
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n], diff[n];
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<n; i++) scanf("%d", &b[i]);
	for(int i=0; i<n; i++) diff[i] = b[i]-a[i];
	//for(int i=0; i<n; i++) printf("%d\n", diff[i]);;
	qsort(diff, n, sizeof(int), compare);
	long long int res=0;
	long long int less_than_zeroes = 0;
	if(binary_search(diff, 0, n, 0) > 0){
		less_than_zeroes = (long long int)binary_search(diff, 0, n, 0);
		res += (less_than_zeroes*(less_than_zeroes+1))/2 - less_than_zeroes;
		//printf("ltz %d\n", less_than_zeroes);
	}
	for(int i=less_than_zeroes; i<n; i++){
		long long  x = (long long int)binary_search(diff, 0, n, 0-diff[i]);
		if(x>0) res += x;
		//printf("%d\n", res);
	}
	printf("%lld", res);
}