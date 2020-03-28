#include <stdio.h>
#include <math.h>
#define MAX 1000000
char nums[MAX] = {0};
int twins[MAX+1] = {0};
int main(){
	int i=3,i1=1, ix, lastI=3;
	for(; i<MAX; i+=10000,lastI=i){
		i1 = 3;
		for(; i1<=ceil(sqrt(i)); i1+=2){
			ix=lastI/i1;
			for(; ix<=i; ix+=i1) nums[ix] = 1;
		}
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
}