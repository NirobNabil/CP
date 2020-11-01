#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, c;
		scanf("%d %d", &n, &k);
		set<int> distincts;
		for(int i=0; i<n; i++) scanf("%d", &c), distincts.insert(c);
		if(distincts.size()>k) printf("-1\n");
		else{
			c=1;
			while(distincts.size()<k){
				distincts.insert(c++);
			}
			printf("%d\n", n*distincts.size());
			for(int i=0; i<n; i++){
				for(auto i : distincts) printf("%d ", i);
			}
			printf("\n");
		}
	}
}