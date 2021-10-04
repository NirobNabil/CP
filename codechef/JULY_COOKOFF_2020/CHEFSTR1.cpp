#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int x, t, n;
	long long int r;
	scanf("%d", &t);
	while(t--){
		r=0;
		int a, b;
		scanf("%d", &n);
		scanf("%d", &a);
		for(int i=1; i<n; i++, a = b) {
			scanf("%d", &b);
			x = abs(a - b);
			if(x) r += x-1;				
		}  
		printf("%ld\n", r);
	}
}