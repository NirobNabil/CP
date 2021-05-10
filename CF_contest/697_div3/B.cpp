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
	unordered_map<int,bool> pos(1000200);
	for(int i=0; i<1000; i++) {
		for(int ix=0; ix<1000; ix++) {
			pos[2020*i + 2021*ix] = 1;
		} 
	}
	while(t--) {
		scanf("%lld", &n);
		if(pos[n]) printf("YES\n");
		else printf("NO\n");
	}
}