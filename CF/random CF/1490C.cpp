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
	ll i, ix, t, n;
	scanf("%lld", &t);
	vector<ll> a;
	for(ll i=1; i<10e4 +9; i++) {
		a.pb(i*i*i);
	} 
	// for(int i=0; i<10e4; i++) 
	// 	cout << a[i] << endl;
	while(t--){
		scanf("%lld", &n);
		bool pos = false;
		for(int i=0; i<10e4 +9 && a[i]<n; i++) {
			// printf("%lld\n", a[i]);
			if(binary_search(a.A(), a.B(), n-a[i])) {
				// printf("%lld %lld\n", n-a[i], binary_search(a.A(), a.B(), n-a[i]));
				pos = 1;		
				break;		
			}
		} 		
		if(pos) printf("YES\n");
		else printf("NO\n");
	}
}