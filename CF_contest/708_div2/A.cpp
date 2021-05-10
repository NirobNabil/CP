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
	int i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		std::vector<int> a(n);
		rep(i, 0, n) scanf("%d", &a[i]);
		map<int,int> occ;
		for(int i=0; i<n; i++) occ[a[i]]++;
		sort(a.A(), a.B());
		a.resize(unique(a.A(), a.B()) - a.A());
		for(auto i:occ) {
			while(i.Y>1) a.pb(i.X), i.Y--;
		}
		for(int i=0; i<a.size(); i++) printf("%d ", a[i]);
		printf("\n");
	}
}