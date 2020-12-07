#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, x;
		scanf("%d %d", &n, &x);
		int a[n], b[n];
		multiset<int> c;
		vector<int> ans;
		bool gg=0;
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<n; i++) scanf("%d", &b[i]), c.insert(b[i]);
		for(int i=0; i<n; i++) {
			auto g = c.upper_bound(x-a[i]);
			if(g==c.begin()) {
				printf("NO\n");
				gg=1;
				break;
			}else {
				c.erase(--g);
				// ans.push_back(*g);
			}
		}
		if(gg!=1) {
			printf("YES\n");
			// for(auto i:ans) printf("%d ", i);
			// printf("\n");
		}
	}
}