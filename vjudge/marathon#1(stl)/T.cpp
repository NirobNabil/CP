#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


int main(){
	int i, ix, t, n, k, a[S1];
	// scanf("%d", &t);
	// while(t--){
		scanf("%d %d", &n, &k);
		rep(i, 0, n) scanf("%d", &a[i]);
		sort(a,a+n);
		int m=0;
		for(int i=0; i<n; i++) {
			if(binary_search(a,a+n,a[i]-k)) m++;
			if(binary_search(a,a+n,a[i]+k)) m++;
		}
		printf("%d\n", m/2);
	// }
}