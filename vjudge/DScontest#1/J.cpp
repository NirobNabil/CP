#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define PUSH(x) if(!visited[x]) { q.push_back(x); visited[x]=1; }
#define item pair<pair<int,int>,int>
#define X first
#define Y second
int k, n, m, x, y, l, ks[105], visited[1005], reachable[1005];
unordered_map<int,unordered_map<int,int> > adj;

deque<int > q;

void bfs(int x) { //y and x are flipped
	q.clear();
	PUSH(x);
	// int gg=20;
	while(q.size()){
		int g = q.front();
		q.pop_front();
		reachable[g]++;
		for(auto i:adj[g]) {
			// printf("%d %d %d\n", g, i.X, adj[g].size());
			PUSH(i.X)
		}
		// printf("\n");
		// printf("%d\n", q.size());
	}
	return;
}



int main(){
	int t;
	scanf("%d", &t);
	for(int ig=1; ig<=t; ig++) {
		memset(reachable, 0, sizeof(reachable));
		adj.clear();
		scanf("%d %d %d", &k, &n, &m);
		for(int i=0; i<k; i++) scanf("%d", &ks[i]);
		int x,y;
		for(int i=0; i<m; i++) {
			scanf("%d %d", &x, &y);
			adj[x][y]=1;
		}
		for(int i=0; i<k; i++) {
			memset(visited, 0, sizeof(reachable));
			bfs(ks[i]);
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(reachable[i]>=k) ans++;
		}
	  printf("Case %d: %d\n", ig, ans);
	}
}