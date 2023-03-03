#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)

#define X first
#define Y second
#define A begin
#define B end
#define S1 200009

ll fact[S1+9];
const ll m = 1000000007;

void cfact(ll n) {
  fact[0] = 1;
  for(ll i=1; i<=n; i++) {
    fact[i] = (fact[i-1] * i) % m;
  }
}


int main(){
	int i, ix, t, n, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	cfact(S1);
	while(t--){
		scanf("%d", &n);
		vector<int> a(n);
    map<int,ll> dbl;
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    	dbl[a[i]]++;
    }
		int x = a[0];
		for(auto i:a) x = x & i;
		if(dbl[x] > 1) {
  	// cerr << fact[n-2] << " " << m << endl;
			printf("%lld\n", (ll)( ( ( dbl[x]*(dbl[x]-(ll)1) )%m ) * fact[n-2] ) % m );
		} else printf("0\n");
	}
}