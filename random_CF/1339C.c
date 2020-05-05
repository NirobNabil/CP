#include <stdio.h>
#include <math.h>
#define MAX(a,b) ((a>b)?a:b)

int main(){
	int t, n, i, nums[100000], diff, pow, maxpow=-1;
	scanf("%d", &t);
	while(t--){
		maxpow=-1;
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d", &nums[i]);
		int lastBig=nums[0];
		for(i=0; i<n; i++){
			if(nums[i]>lastBig) lastBig=nums[i];
			else{
				diff = lastBig-nums[i];	
				while(diff){
					pow = (int)log2(diff);
					maxpow = MAX(pow, maxpow);
					diff -= 1<<pow;
				}
			}
		}
		printf("%d\n", maxpow+1);
	}
}