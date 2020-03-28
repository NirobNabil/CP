#include <stdio.h>
#define MAX 100000000
char nums[MAX+1] = {0};
int twins[MAX+1] = {0};
int main(){
	int i=3, ix;
	for(; i<=10000; i+=2){
		ix=i+i;
		if(!nums[i]) for(; ix<=MAX; ix+=i) nums[ix] = 1; 
	}
	int next = 1;
	i=3;
	for(; i<=MAX-2; i+=2){
		if(!nums[i] && !nums[i+2]) twins[next]=i, next++;
	} 
	int a;
	while(scanf("%d", &a) != EOF){
		printf("(%d, %d)\n", twins[a], twins[a]+2);
	}
	return 0;
}