#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, n, x, y;
	scanf("%d", &t);
	while(t--){
		unordered_map<int, int> Xs(200009), Ys(200009);
		unordered_set<int> Xi(200009), Yi(200009);
		scanf("%d", &n);
		n = 4*n -1;
		while(n--){
			scanf("%d %d", &x, &y);
			Xs[x]++, Ys[y]++;
			Xi.insert(x);
			Yi.insert(y);
		}
		for(auto i : Xi) {
			if(Xs[i]%2==1){
				x = i;
				break;
			}
		}
		for(auto i : Yi) {
			if(Ys[i]%2==1){
				y = i;
				break;
			}
		} 
		printf("%d %d\n", x, y);
	}

}
