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
		vector<int> a(n), b(n), c;

		int cur = 0;
		set<int> pool1;
		for(int i=1; i<=n; i++) pool1.in(i);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    	if(a[i] != cur) {
    		b[i] = a[i];
    		cur = a[i];
    		c.pb(i);
    		pool1.del(a[i]);
    	}
    }

    c.pb(n);
    set<int> pool = pool1;
    for(int i=0; i<c.size()-1; i++) {
    	int ix = c[i]+1;
    	while(ix != c[i+1]) {
    		b[ix++] = *pool.A();
    		pool.del(pool.A());
		    // cerr << ix-1 << "-" << b[ix-1] << endl;
    	}
    } 
   	
   	for(auto i:b) printf("%d ", i);
   	printf("\n");

    pool = pool1;
    for(int i=0; i<c.size()-1; i++) {
    	int ix = c[i]+1;
    	while(ix != c[i+1]) {
    		auto it = --pool.lower_bound(b[c[i]]);
    		b[ix++] = *it;
    		pool.del(it);
		    // cerr << ix-1 << "-" << b[ix-1] << endl;
		    // cerr << ix-1 << "-" << b[ix-1] << endl;
    	}
    } 

		for(auto i:b) printf("%d ", i);
   	printf("\n");



	}
}