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
#define S1 100000



int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n = n+2;
		multiset<int> a;
		vector<int> b(n);
		for(int i=0; i<n; i++) {
    	scanf("%d", &b[i]);
    	a.insert(b[i]);
    }
    ll s = 0, c=0, p = 0;
    for(auto i:a) s += i;
    for(int i=0; i<n; i++) {
    	c = s - b[i];
    	a.erase(a.lower_bound(b[i]));
    	// printf("%d %d\n", b[i], *a.rbegin());
    	if(c % 2 == 0 && *a.rbegin() == c/2 ) {
    		auto itx = --a.B();
    		for(auto it = a.A(); it != itx; it++) {
    			printf("%d ", *it);
    		} 
  			printf("\n");
    		p = 1;
    		break;
    	}
    	a.insert(b[i]);
    }

    if(!p) printf("-1\n");
	}
}