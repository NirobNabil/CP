#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, n, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		x = n/4 + ((n%4)?1:0);
		for(int i=0; i<n-x; i++) printf("9");
		for(int i=0; i<x; i++) printf("8");
		printf("\n");
	}
}