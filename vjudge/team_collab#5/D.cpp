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
	int x, i, ix, t, n;
	scanf("%d", &n);
  set<pair<int,int> , greater<pair<int,int> > > bm;
	vector<pair<int,int> > a(n), b(n);
	rep(i, 0, n) scanf("%d", &x), a[i] = {x, i};
	for(int i=0; i<n; i++) {
		scanf("%d", &x); 
		b[i] = {x, i}; 
		bm.insert({x,i});
		a[i].Y = x;
	}
	sort(a.A(), a.B(), greater<pair<int,int> >());
	int moves = 0;
	multiset<pair<int,int> > q;
	for(int i=n-1; i>=0; ) {
		// if(moves == i+1) {
		// 	while(i>=0) q.insert(b[i].X);
		// 	break;
		// }
		while(!q.empty() && q.rbegin()->X < b[i].X && i>=0) {
			q.erase(--q.end());
			q.insert(b[i]);
			i--;
		}
		// cerr << "xd" << i << " " << moves << endl;
		bm.erase(b[i]);
		i--;
		moves++;
		while(i>=0) {
			// cerr << "gg" << i << " " << moves << endl;
			auto it = bm.A();
			advance(it, n/2 - q.size() -1);
			// for(auto i:bm) printf("%d ", i.X);
			// printf("\n");
			if(b[i].X < it->X || !moves) break;
			q.insert(b[i]);
			bm.erase(b[i]);
			i--;
			moves--;
		}
	} 
	ll ans = 0;
	// for(auto i:q) printf("xx %d\n", i);
	for(auto i:q) ans += i.X;
	printf("%lld\n", ans);
}