#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000000
#define MAX( a, b ) ( ( a > b) ? a : b )
#define MIN( a, b ) ( ( a < b) ? a : b )
#define ull unsigned long long

ull len[SIZE+1]={0};
ull max[SIZE+1][22]={0};

int pow2(ull x){
    return 1<<x;
}

void build_sparse(){
	int ig=1;
	for(; ig<=SIZE; ig++){
		max[ig][0] = len[ig];
	}
	int log = (int)log2(SIZE)+1;
	int ix=1;
	for(; ix<=log; ix++){
	    int i=1;
		for(; i<=SIZE; i++){
      		/*printf("%d %d", ix, i);*/
			max[i][ix] = MAX(max[i][ix-1], max[MIN(SIZE, i+pow2(ix) -pow2(ix-1))][ix-1]);
		}
	}
}

ull alg(ull n, ull depth){
	if(n==1) return ++depth;
	else if(n%2==1){
		n=3*n+1;
	}else if(n%2==0){
		n/=2;
	}
	depth++;
	/*printf("%d %d\n", n);*/
	if(n>SIZE) return alg(n, depth);
	else if(len[n] != 0) return len[n]+depth;
	else{
		len[n] = alg(n, 0);
		return len[n] + depth;
	}
}

int main(){
	ull i=SIZE;
	for(; i>0; i--){
		if(len[i] == 0){
	      /*printf("%d\n", i);*/
	      len[i] = alg(i, 0);
		}
	}
	ull a, b;
	build_sparse();
	while(scanf("%llu %llu", &a, &b) != EOF){
		int x = MAX(a,b);
		int y = MIN(a,b);
		int max_p = (int)log2(y-x+1);
		printf("%llu %llu %llu\n", a, b, MAX(max[x][max_p], max[y-pow2(max_p)+1][max_p]));
		/*ull gg=0;
		i=a;
		for(; i<=b; i++) gg=MAX(gg, len[i]);
		printf("%llu %llu %llu\n", a, b, gg);*/
	}
	return 0;
}
