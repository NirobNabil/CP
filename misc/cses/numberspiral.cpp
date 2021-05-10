#include "bits/stdc++.h"
using namespace std;
#define ll long long int

long long int getSq(long long int n){
	return n*n;
}

void numspi(int x, int y){
	long long int c=0, g=y, h=x;
	if(x>y) c=1, g=x, h=y;
	if(g%2==c){
		printf("%lld ", getSq(g)-h+1);
	}else {
		printf("%lld ", getSq(g-1)+h);
	}
}

int main(){
	int t;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			numspi(i,j);
		} 
		printf("\n");
	}
}