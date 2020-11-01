#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	set<int> b;
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		if(b.find(a[i]) != b.end()) {
			printf("NO\n");
			return 0;
		}
		b.insert(a[i]);
	}
	int i=n-1;
	while(a[i-1]>a[i] && --i>0) continue;
	while(a[i-1]<a[i] && --i>0) continue;
	if(i<=0) printf("YES\n");
	else printf("NO\n");
}