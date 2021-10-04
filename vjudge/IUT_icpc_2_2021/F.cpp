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
#define pp pair<int,int>

bool cmp(pp x, pp y) {
	return (y.X <= x.Y);
}

int main(){
	int i, ix, t, n, x, y;
	vector<pp > a;
	while(scanf("%d", &n) != EOF){
		rep(i, 0, n) {
			scanf("%d %d", &x, &y);
			a.push_back({x,y});
		} 
		qsort(a.A(), a.B(), cmp);
		for(auto i:a) {
			cout << i.X << " " << i.Y << "\n";
		}
	}
}