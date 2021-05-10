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
	int i, ix, t, n, m, a[S1], b[S1], c[S1], d[S1];
	multimap<int,int > e;
	scanf("%d", &t);
	while(t--){
		e.clear();
		scanf("%d %d", &n, &m);
		rep(i, 0, n) scanf("%d", &a[i]);
		rep(i, 0, n) scanf("%d", &b[i]);
		rep(i, 0, m) scanf("%d", &c[i]);
		rep(i, 0, m) {
			e.insert({c[i], i});
		}
		bool pos = true;
		int mx = -1;
		for(int i=0; i<n; i++) {
			auto itp = e.equal_range(b[i]);
			auto it = itp.Y;   
			--it;
			if(a[i]==b[i] && itp.X==itp.Y) continue;
			if(itp.X == itp.Y) {
				pos = false;
				break;
			}
			mx = max(mx, it->Y);
			// printf("c %d %d\n", i, it->Y);
			d[it->Y] = i+1;
			if(a[i] != b[i]) e.erase(it);
		}
		for(auto i:e) {
			// cout << i.Y << endl;
			if(i.Y>mx) { pos=false; break; }
			d[i.Y] = d[mx];
		}
		// printf("pos %d\n", pos);
		if(pos) {
			printf("YES\n");
			for(int i=0; i<m; i++) printf("%d ", d[i]);
			printf("\n");
		}else printf("NO\n");
	}
}