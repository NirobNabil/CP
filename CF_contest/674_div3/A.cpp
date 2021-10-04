#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,x;
		scanf("%d %d", &n, &x);
		if(n>2){
			n-=2;
			printf("%d\n", n/x + 1 + ((n%x==0)?0:1));
		}else{
			printf("%d\n", 1);
		}
	}
}