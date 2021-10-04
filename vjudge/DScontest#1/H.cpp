#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define PUSH(x, y, l) if(!visited[x][y]) { q.push_back({{x,y},l}); visited[x][y]=1; }
#define item pair<pair<int,int>,int>
#define X first
#define Y second
char grid[30][30];
int visited[30][30];
ll cost[30][30] = {0};
int r, c, x, y, l;

deque<item > q;

int bfs(int x, int y) { //y and x are flipped
	q.clear();
	PUSH(x,y,0);
	while(q.size()){
		item g = q.front();
		q.pop_front();
		x = g.X.X;
		y = g.X.Y;
		l = g.Y;
		// printf("%d %d %d\n", x,y,l);
		// if(y>=r || y<0 || x>=c || x<0) continue;
		if(grid[x][y] == 'h') return l;
		else if(grid[x][y] == '#' || grid[x][y] == 'm') continue;
		else {
			PUSH( x+1,y, l+1);
			PUSH( x-1,y, l+1);
			PUSH( x,y+1, l+1);
			PUSH( x,y-1, l+1);
		}
		// printf("%d\n", q.size());
	}
	return 0;
}


vector<pair<int,int> > puffs;
int main(){
	int t;
	scanf("%d", &t);
	for(int ig=1; ig<=t; ig++) {
		puffs.clear();
		scanf("%d %d", &r, &c);
		char s[c+5];
		for(int i=0; i<r; i++) {
			scanf("%s", &s);
			// printf("\n");
			for(int ix=0; ix<c; ix++) {
				// printf("%c ", s[ix]);
				grid[ix][i] = s[ix];
				if(grid[ix][i]=='a' || grid[ix][i]=='b' || grid[ix][i]=='c') {
					// printf("%d %d %c\n", ix, i, grid[ix][i]);
					puffs.push_back({ix,i});
				}
			}
		}
		// printf("%d %d\n", puffs[0].first, puffs[0].second);
		
		int x=0;
		for(int i=0; i<puffs.size(); i++) {
			memset(visited, 0, sizeof(visited));
			x = max(x, bfs(puffs[i].X, puffs[i].Y));
		} 
		printf("Case %d: %d\n", ig, x);
	}
}