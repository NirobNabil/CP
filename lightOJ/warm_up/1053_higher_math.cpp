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
	int i, ix, t, n, tc=0;
	ll a[3];
	scanf("%d", &t);
	while(++tc <= t){
		scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
		for(int i=0; i<3; i++) a[i] = a[i]*a[i];
		int pos = 0;
		for(int i=0; i<3; i++) {
			if(a[i] + a[(i+1)%3] == a[(i+2)%3]) {
				pos = 1;
				break; 
			}
		} 
		printf("Case %d: %s\n", tc, pos?"yes":"no");
	}
}