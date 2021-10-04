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

unordered_map<int, unordered_map<int,int> > map;
int checked[S1], min_path[S1], animals[S1];

int check(int i) {
	if(min[i]) return min[i];
	for(auto a:map[i]) {
		if(a.X == i) continue;
		min[i] = min(min[i], check(a.X));
	}
	min[i] += animals[i];
}

int main(){
	int i, ix, t, n, x, y;
	scanf("%d %d", &n, &m);
	rep(i, 0, n) scanf("%d", &animals[i]);
	for(int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}

}