#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n, k1, k2, w, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &n, &k1, &k2, &w, &b);
		int j1 = n-k1, j2= n-k2;
		w -= min(k1,k2) + ( max(k1, k2) - min(k1, k2) ) / 2;
		b -= min(j1,j2) + ( max(j1, j2) - min(j1, j2) ) / 2;
		if(w < 1 && b < 1) printf("YES\n");
		else printf("NO\n");
	}
}