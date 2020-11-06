#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, n, d;
	int a[100009];
	vector <int> b;
	scanf("%d", &t);
	while(t--){
		d=0;
		b.clear();
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			// printf("%d ", a[i]);
		}
		if(a[1]>a[0]) d = 1;
		else d=-1;
		b.push_back(a[0]);
		for(int i=1; i<n; i++) {
			if((a[i]-a[i-1])*d < 0) b.push_back(a[i-1]), d = (d==1)?-1:1;
		}
		if(a[n-1]!=a[n-2] || b.size()<2 ) b.push_back(a[n-1]);
		printf("%d\n", b.size());
		for(auto i:b) printf("%d ", i);
		printf("\n");
	}
}