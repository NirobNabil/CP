#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n, k, h[S1];
	scanf("%d", &t);
	vector<int> v;
	while(t--){
		scanf("%d %d", &n, &k);
		rep(i, 0, n) scanf("%d", &h[i]);
		int pos = 1;
		std::vector<int> imx(n+9), imn(n+9);
		imx[0] = h[0] + k;
		imn[0] = h[0] + 1;
		// printf("%d %d\n", imn[0], imx[0]);
		for(int i=1; i<n; i++) {
			imx[i] = min(imx[i-1] + k-1, h[i] + k + k-1);
			imn[i] = max(imn[i-1] - k+1, h[i] + 1);
			// printf("%d %d\n", imn[i], imx[i]);
			if(imx[i] - imn[i] < k-1) {
				pos = 0;
				break;
			}
		}
		if(imn[n-1] != h[n-1]+1) pos = 0;
		printf("%s\n", pos?"YES":"NO");
	}
}