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
	int xd=0;
	while(q.size()){
		item g = q.front();
		q.pop_front();
		x = g.X.X;
		y = g.X.Y;
		// printf("%d %d - %d %d %d %d\n", r,c,x,y,l,(y>=r || y<0 || x>=c || x<0));
		// if(y>=r || y<0 || x>=c || x<0) continue;
		if(y>=r || y<0 || x>=c || x<0) continue;
		else if(grid[x][y] == '#') continue;
		else {
			PUSH( x+1,y, 0);
			PUSH( x-1,y, 0);
			PUSH( x,y+1, 0);
			PUSH( x,y-1, 0);
		}
		xd++;
		// printf("%d\n", q.size());
	}
	return xd;
}

int main(){
	int t;
	scanf("%d", &t);
	// printf("%d\n", t);
	for(int ig=1; ig<=t; ig++) {
		scanf("%d %d", &c, &r);
		// printf("%d %d\n", r,c);
		char s[c+5];
		int ggg;
		pair<int,int> init;
		for(int i=0; i<r; i++) {
			scanf("%s", &s);
			// printf("%s\n", s);
		// 	// printf("\n");
			for(int ix=0; ix<c; ix++) {
				// printf("%c ", s[ix]);
				grid[ix][i] = s[ix];
				if(grid[ix][i]=='@') init.X=ix, init.Y=i;
			}
		}
		// for(int i=0; i<r; i++) {
		// 	// scanf("%s", &s);
		// 	for(int ix=0; ix<c; ix++) {
		// 		// printf("%c ", grid[ix][i]);
		// 		// grid[ix][i] = s[ix];
		// 		// if(grid[ix][i] == '@') init.X=ix, init.Y=i;
		// 	}
		// 	printf("\n");
		// }
		// printf("%d -c %c %d %d\n", r, grid[init.X][init.Y], init.X,init.Y);
		memset(visited, 0, sizeof(visited));
		ggg=bfs(init.X, init.Y);
	  printf("Case %d: %d\n", ig, ggg);
	}
}