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
	int i, ix, t, n, a, b, x[S1], y[S1], k;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &k);
		rep(i, 0, k) scanf("%d", &x[i]);
		rep(i, 0, k) scanf("%d", &y[i]);
		unordered_map<int,int> boy, girl;
		for(int i=0; i<k; i++) {
			boy[x[i]]++;
			girl[y[i]]++;
		}
		ll ans = 0;
		for(int i=0; i<k; i++) {
			ans += k - boy[x[i]] - girl[y[i]] + 1; 
		}
		printf("%lld\n", ans>>1);
	}
}