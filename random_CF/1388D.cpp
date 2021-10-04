#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int t, n, b[200005];
ll sum, a[200005];
set<int> c, x;
unordered_map<int, vector<int> > d;
list<int> e;

list<int> maximize(int i){
	// printf("%d %d ", i, a[i]);
	list<int> tt, temp;
	tt.push_back(i);
	for(auto ix:d[i]) {
		if(c.find(ix) != c.end()) {
			temp = maximize(ix);
		}
		// printf("%d ", a[ix]);
		if(a[ix]>0) {
			tt.splice(tt.end(), temp);
			// for(auto ix:temp) t1.push_back(ix);
		}else {
			tt.splice(tt.begin(), temp);
			// for(auto ix:temp) t2.push_back(ix);
		}
		a[i] += (a[ix]>0)?a[ix]:0;
	}
	// printf("%d - ", a[i]);
	// for(auto ix:tt) printf("%d ", ix);
	// printf("\n");
	// t1.push_back(i);
	// t1.splice(t1.end(), t2);
	// for(auto ix:t2) t1.push_back(ix);
	sum += a[i];
	c.erase(i);
	return tt;
}

int main(){
	// scanf("%d", &t);
	// while(t--){
		vector<int> temp;
		scanf("%d", &n);
		c.clear();
		d.clear();
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]), c.insert(i);
		for(int i=1; i<=n; i++) {
			scanf("%d", &b[i]);
			d[b[i]].push_back(i);
			if(b[i]==-1) x.insert(i);
		}
		while(c.size() && x.size()) {
			// printf("%d\n", *x.begin());
			e.splice(e.begin(), maximize( *x.begin() ));
			c.erase(*x.begin());
			x.erase(x.begin());
			// for(auto i:temp) e.push_back(i);
		}
		printf("%lld\n", sum);
		for(auto i=e.rbegin(); i!=e.rend(); i++)  printf("%d ", *i);
		printf("\n");
	// }
}