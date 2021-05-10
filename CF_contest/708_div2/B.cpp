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
		int i, ix, t, n, m;
		scanf("%d", &t);

		while(t--){
			scanf("%d %d", &n, &m);
			vector<int> v(n), r(n), p(n);
			multiset<pair<int,int> > mod;
			for(int i=0; i<n; i++) p[i] = i;

			rep(i, 0, n) scanf("%d", &v[i]);
			for(int i=0; i<n; i++) v[i] %= m;
			sort(v.A(), v.B());
			
			for(int i=0; i<n; i++) {
				mod.insert(make_pair(v[i], i));
				r[i] = (CEIL(v[i],m) * m) - v[i];
			}
			
			int c = 1, ci=0;
			vector<int> carr = {0};

			while(mod.size()) {
				i = carr.back();
				p[i] = -1;
				mod.erase({v[i], i});
				auto it = mod.lower_bound({r[i],-1});
				if(it == mod.end() || it->X != r[i]) {
					if(mod.size() != 0) c++;
					carr.clear();
					while(ci < n && p[ci] == -1) ci++;
					if(ci < n) carr.pb(p[ci++]);
				} else {
					carr.pb(it->Y);
					mod.erase(it);
				}

			}
			printf("%d\n", c);
		}
	}