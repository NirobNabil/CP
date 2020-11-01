#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		int p=0,q=0;
		for(int i=0; i<n; i++) {
			if(p==a[i]) {
				p++;
			}else if(q==a[i]){
				q++;
			}
		} 
		printf("%d\n", p+q);
	}
}