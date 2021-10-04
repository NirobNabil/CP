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
	int i, ix, t, n, q, a[S1];
	multiset<pair<int,int> > c_p;
	vector<int> c_m;
	int i_m = 0;
	scanf("%d", &n);
	while(n--) {
		
		scanf("%d", &q);
		
		if(q == 1) {
			scanf("%d", &ix);
			c_m.pb(ix);
			c_p.insert({ix, c_m.size()-1});
		
		}else if(q == 2) {
			while(c_m[i_m] == -1) i_m++;
			printf("%d ", i_m +1);
			c_p.erase(c_p.lower_bound({c_m[i_m], i_m}));
			c_m[i_m++] = -1;
		
		}else { 
			auto it = c_p.lower_bound( {c_p.rbegin()->X, -1} );
			printf("%d ", it->Y +1);
			c_m[it->Y] = -1;
			c_p.erase(it);
		}
	}
	printf("\n");
}