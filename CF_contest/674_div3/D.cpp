#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define ABS(A) ((A<0)?A*-1:A)

int main(){
	unordered_map<int,int> c;
		int n;
		c.clear();
		scanf("%d", &n);
		int a[n], b[n], d[n];
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		b[0]=a[0];
		for(int i=1; i<n; i++) {
			b[i] = b[i-1]+a[i];
			c[b[i]] = i; 
		}
		int ans=0;
		bool first=false;
		for(int i=0; i<n; i++) {
			if(b[i]==0 && !first) ans++;
			if(c[b[i]] && c[b[i]]>i) {
				first=true;
				ans++;
			}
		}
		for(auto i:b) printf("%d ", i);
		printf("\n");
		printf("%d\n", ans);
}