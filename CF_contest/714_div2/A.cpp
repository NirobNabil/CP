#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int main(){
	int i, ix, t, n, k, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		std::vector<int> v1;
		for(int i=0, ni=n-k+1; i<k; i++, ni++) {
			v1.pb(ni);
		} 

		if(n-k < k+1) {
			printf("-1\n");
		}else {
			int i=0;
			for(int iv=0; i<n && iv<k; i++, iv++) {
				printf("%d %d ", i+1, v1[iv]);
			}
			while(i<n-k) {
				printf("%d ", 1 + i++);
			}
			printf("\n");
		}
	}
}