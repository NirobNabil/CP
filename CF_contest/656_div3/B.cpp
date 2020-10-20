#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool gg[55];

int main(){
	int t, n, h;
	scanf("%d", &t);
	while(t--){
		memset(gg, 0, sizeof(gg));
		vector<int> p;
		scanf("%d", &n);
		for(int i=0; i<2*n; i++){
			scanf("%d", &h);
			if(gg[h]) continue;
			else {
				p.push_back(h);
				gg[h]=1;
			}
		}
		for(auto i : p) {
			printf("%d ", i);
		}
		printf("\n");
	}
}