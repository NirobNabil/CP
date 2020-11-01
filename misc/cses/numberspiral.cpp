#include "bits/stdc++.h"
using namespace std;
#define ll long long int

long long int getSq(long long int n){
	return n*n;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int x,y;
		scanf("%d %d", &y, &x);
		long long int c=0, g=y, h=x;
		if(x>y) c=1, g=x, h=y;
		if(g%2==c){
			printf("%lld\n", getSq(g)-h+1);
		}else {
			printf("%lld\n", getSq(g-1)+h);
		}
	}
}