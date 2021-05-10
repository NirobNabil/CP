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
#define CEIL(a,b) ( (a)%(b) ? (a)/(b)+1 : (a)/(b) )

int main(){
	int i, ix, t, n, m, k, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		vector<vector<int> > v(m);
		for(int i=0; i<m; i++) {
			scanf("%d", &k);
			for(int ix=0; ix<k; ix++) {
				scanf("%d", &x);
				v[i].pb(x);
			}
		}
		set<pair<int,int> > s;
		for(int i=0; i<m; i++) {
			s.insert({v[i].size(), i});
		}
		vector<int> f(m);
		map<int,vector<int> > called;
		int pos = 1;
		for(auto i:s) {
			if(called[v[i.Y][0]].size() < CEIL(m,2)) called[v[i.Y][0]].pb(i.Y);
			else if(v[i.Y].size()>1 && called[v[i.Y][1]].size() < CEIL(m,2)) 
				called[v[i.Y][1]].pb(i.Y);
			else pos = 0;
			// printf("%d %d\n", v[i.Y][0], i.Y);
		}

		if(pos) {
			printf("YES\n");
			std::vector<int> g(m);
			for(auto i:called) {
				for(auto ix:i.Y) {
					g[ix] = i.X;
				}
			}
			for(int i=0; i<g.size(); i++) printf("%d%c", g[i], " \n"[i==g.size()-1]); 
		}else printf("NO\n");

	}
}