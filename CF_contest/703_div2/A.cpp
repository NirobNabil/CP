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
	long long int i, ix, t, n, a[S1], b[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		rep(i, 0, n) scanf("%lld", &a[i]);
		b[0]=a[0];
		bool gg = true;
		for(int i=1; i<n; i++) {
			b[i] = a[i]+b[i-1];
			if(b[i] < ((i+1)*(i+1-1))/2) {
				printf("NO\n");
				gg=false;
				break;
			}
		}
		if(gg) printf("YES\n");
	}
}