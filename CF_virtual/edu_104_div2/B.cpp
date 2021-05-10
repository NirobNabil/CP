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

		// for(int c=0, i=1, ix=n; c<100; c++) {
		// 	printf("%d %d ", i,ix);
		// 	ix--;
		// 	if(ix<1) ix=n;
		// 	++i;
		// 	if(i>n) i=1;
		// 	if(i==ix) printf("s %d ", i), ++i;
		// 	if(i>n) i=1;
		// 	printf("\n");
		// }


int main(){
	int t, n, k, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		k--;
		if(n%2==1) 
			printf("%d\n", (k+k/(n/2))%n +1);
		else printf("%d\n", k%n +1);
	}
}