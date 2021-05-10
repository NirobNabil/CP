#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n, m;
	char s[S1];
	map<int,int> x,y;
	map<int, map<int,int> > grid;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%s", &s);
		for(int ix=0; ix<m; ix++) {
			if(s[ix] == '*') 
				x[ix]++, y[i+1]++, grid[ix][i+1] = 1;
		}
	}
	int xmax = 0, ymax = 0, cker;
	int pos = 1;
	for(xmax=0; xmax<m; xmax++) {
		vector<int> dx, deviant_y;
		pos = 1;
		for(auto i:x) {
			if(i.X != xmax) {
				if(i.Y == 1) dx.pb(i.X);
				else if(i.Y < 1) continue;
				else pos = 0;
			}
		}
		cker = INT_MIN;
		for(auto i:dx) {
			// printf("c ");
			if(cker == INT_MIN) cker = grid[i].begin()->X;
			else if(grid[i].begin()->X != cker) {
				pos = 0;
				break;
			}
		}
		if(pos) {
			printf("%s\n%d %d", "YES", cker==INT_MIN?1:cker, xmax+1);
			return 0;
		}	
	} 
	printf("%s\n", "NO");
}