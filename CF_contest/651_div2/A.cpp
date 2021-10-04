#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000

// int primes[max+1] = {0};
int nums[MAX+1];
int m[MAX+1];
void generate(){
		nums[0] = 1;
		nums[1] = 1;
    int i=1, ix;
    for(; i<=MAX/2; i++){
    	for(ix=i*2; ix<=MAX; ix+=i){
    		nums[ix] = i;
    	} 
    }
}

int main(){
	int t, n, cur_max;
	generate();
	m[0]=1;
	for(int i=1; i<=MAX; i++) {
		// if(nums[i] > nums[i-1]) m[i] = i;
		// else m[i] = m[i-1], nums[i] = nums[i-1];
		// printf("%d\n", nums[i]);
		nums[i] = max(nums[i-1], nums[i]);
	}
	scanf("%d", &t);
	while(t--){
		cur_max=0;
		scanf("%d", &n);
		printf("%d\n", nums[n]);
	}
}