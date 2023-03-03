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

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main(){
	int x,y,i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> p(n+9, -1);
		vector<pair<int,int> >  w;
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			w.push_back({x,i});
		}
		for(int i=0; i<n-1; i++) {
			scanf("%d %d", &x, &y);
			p[x]++;  p[y]++;
		} 
		sort(w.A(), w.B(), greater<pair<int,int>>());
		// for(int i=0; i<n; i++) printf("%d %d\n", w[i].X, w[i].Y);
		// for(int i=1; i<=n; i++) printf("%d ", p[i]);
		// printf("\n");
		ll sum = 0;
		for(int i=0; i<n; i++) sum += w[i].X;
		printf("%lld ", sum);
		auto it = w.begin();
		for(int i=2; i<n; i++) {
			while(p[it->Y]<1) it++;
			if(it == w.end()) break;
			printf("%lld ", sum += it->X);
			--p[it->Y];
		}
		printf("\n");
	}
}