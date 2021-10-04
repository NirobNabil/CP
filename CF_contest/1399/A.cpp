#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, t=0;
		scanf("%d", &n);
		int a[n];
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		for(int i=0; i<n-1; i++) {
			if( a[i+1] - a[i] == 1 || a[i+1]==a[i]) continue;
			else printf("NO\n"), t=-100;
		}
		if(t!=-100) printf("YES\n");
	}
}