#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define PUSH(x,l) if(!visited[x]) { q.push_back({x,l}); visited[x]=1; }
#define item pair<int, int >
#define X first
#define Y second
int  k, n, m, x, y, l, s, d, ans, path[1005][2], visited[1005];
unordered_map<int ,unordered_map<int ,int > > adj;

void bfs(int x, int j) { //y and x are flipped
	deque<item > q;
	q.clear();
	PUSH(x, 0);
	// int gg=20;
	while(q.size()){
		item g = q.front();
		q.pop_front();
		k = g.X;
		l = g.Y;
		path[k][j] = l;
		for(auto i:adj[k]) {
			// printf("%d %d %d %d\n", k, i.X, l, adj[k].size());
			PUSH(i.X, l+1)
		}
	}
	return;
}



int main(){
	int t;
	scanf("%d", &t);
	for(int ig=1; ig<=t; ig++) {
		memset(path,0,sizeof(path));
		ans=0;
		adj.clear();
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++) {
			scanf("%d %d", &x, &y);
			adj[x][y]=1;
			adj[y][x]=1;
		}
		scanf("%d %d", &s, &d);
		memset(visited,0,sizeof(visited));
		bfs(s,0);
		memset(visited,0,sizeof(visited));
		bfs(d,1);
		for(int i=0; i<n; i++) {
			// printf("%d - %d %d\n", i, path[i][0], path[i][1]);
			ans = max(ans, path[i][0]+path[i][1]);
		}
	  printf("Case %d: %d\n", ig, ans);
	}
}