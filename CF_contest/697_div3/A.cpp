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
	ll i, ix, t, n, a[S1];
	scanf("%lld", &t);
	while(t--){
		i=0;
		scanf("%lld", &n);
		while(n>1) {
			if(n%2 == 1) {
				printf("YES\n");
				i=1;
				break;
			}else {
				n /= 2;
			}
		}
		if(i==0) printf("NO\n");
	}
}