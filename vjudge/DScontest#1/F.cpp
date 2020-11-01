#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int n, q, c;
	scanf("%d %d", &n, &q);
	int a[n+5];
	set<int> b;
	for(int i=0; i<n; i++) scanf("%d", &a[i]); 
	while(q--){
		b.clear();
		scanf("%d", &c);
		int i=0, m=INT_MAX;
		for(; i<c; i++) b.insert(a[i]); 
		// printf("%d ", *b.rbegin());
		m = min(m,*b.rbegin());
		for(; i<n; i++) {
			b.erase(a[i-c]);
			b.insert(a[i]);
			// printf("%d/%d ", i,*b.rbegin());
			m = min(m,*b.rbegin());
		}
		printf("%d\n", m);
	}
}