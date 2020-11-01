#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a>b)?b:a)

// int coo[2001][2] = {0};

int main(){
	// unordered_map<int, int> a;
	int n;
	scanf("%d", &n);
	int arr_in[n+5] = {0};
	int arr_out[n+5] = {0};
	int p,q;
	// memset(arr, n, 0);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &p, &q);
		arr_in[q]++;
		arr_out[p]++;
	}
	for(int i=1; i<=n; i++) {
		printf("node- %d -> outdegree- %d indegree- %d\n", i, arr_in[i], arr_out[i]);
	}
}