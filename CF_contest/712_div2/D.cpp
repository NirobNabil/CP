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
#define cox pair<int,int>

int grid[109][109];
int i, ix, t, n, x, a[S1];

int chk(int i, int j, int x) {
	set<int> a = {1,2,3};
	a.erase(x);
	if(i-1 < 0 && j-1 < 0) return *a.begin();
	if(i-1 >=0) a.erase(grid[i-1][j]);
	if(j-1 >=0) a.erase(grid[i][j-1]);
	if(i-1>=0 && j-1>=0 && i==n-1 && grid[i-1][j] == 0) return grid[i-1][j-1];
	if(j-1>=0 && i+1<n && a.find(grid[i+1][j-1]) != a.end()) {
		// printf("s1 %d %d\n", i-1, j-1);
		return grid[i+1][j-1];
	}else if(i+1<n && j-1>=0 && x == grid[i+1][j-1] && grid[i+1][j] == 0) {
		// printf("s2 %d %d\n", i-1, j-1);
		return -1;
	}
	// printf("sz %d\n", a.size());
	return *a.begin();
}

int main(){
	scanf("%d", &n);
	stack<cox > coo;

	for(int i=n-1; i>=0; i--) {
		for(int ix=n-1; ix>=0; ix--) {
			coo.push({ix,i});
			// cout << i << " " << ix << endl;
		}
	}
	for(int i=0; i<n*n; i++) {
		scanf("%d", &x);
		cox a = coo.top();
		int y = chk(a.X, a.Y, x);
		if(y != -1) {
			// printf("CAME1\n");
			cout << y << " " << a.X+1 << " " << a.Y+1 << endl;
			grid[a.X][a.Y] = y;
			coo.pop();
		}else {
			// printf("CAME2\n");
			coo.pop();
			cox b = coo.top();
			int z = chk(b.X, b.Y, x);
			cout << z << " " << b.X+1 << " " << b.Y+1 << endl;
			grid[b.X][b.Y] = z;
			coo.pop();
			coo.push(a);
		}
	}
	return 0;
}