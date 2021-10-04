#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, n, m, h, gg;
	scanf("%d", &t);
	while(t--){
		gg=0;
		unordered_set<int> a;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) scanf("%d", &h), a.insert(h);
		for(int i=0; i<m; i++) {
			scanf("%d", &h);
			if(a.find(h)!=a.end()) gg=h;
		}
		if(gg) {
			printf("YES\n1 %d\n", gg);
		}else printf("NO\n");
	}
}