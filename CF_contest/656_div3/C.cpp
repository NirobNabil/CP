#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, n, h, m, xd, gg;
	scanf("%d", &t);
	while(t--){
		m=0; xd=0;
		scanf("%d", &n);
		vector<int> a;
		for(int i=0; i<n; i++) {
			scanf("%d", &h);
			a.push_back(h);
		}
		int i=n-1;
		while(a[i-1]>=a[i] && --i>0) continue;
		while(a[i-1]<=a[i] && --i>0) continue;
		printf("%d\n", max(0,i));
	}
}