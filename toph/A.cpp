#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		int g=0, t=0;
		scanf("%d", &n);
		while(n){
			if( n%2 == 1) g++;
			n = n>>1;
		}
		while(g){
			t += 1<<g;
			g--;
		}
		printf("%d\n", t+1<<g );
	}
}