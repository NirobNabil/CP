	#include "bits/stdc++.h"
	using namespace std;
	#define ll long long int
	#define PUSH(x) if(!visited[x]) { q.push_back(x); visited[x]=1; }
	#define item pair<int,int>
	#define X first
	#define Y second
	#define A begin()
	#define B rbegin()
	int k, n, m, x, y, u,v, w,l, c, p, pc, r;
	item g;
	unordered_map<int,unordered_map<int,int> > adj;
	unordered_map<int, pair<int,int> > d;

	int main(){
		int gg=100000;
		scanf("%d %d", &n, &r);
		for(int i=0; i<r; i++) {
			scanf("%d %d %d", &x, &y, &w);
			if(adj[x].find(y)!=adj[x].end()) adj[x][y] = min(w,adj[x][y]);
			else adj[x][y] = w;
			if(adj[y].find(x)!=adj[y].end()) adj[y][x] = min(w,adj[y][x]);
			else adj[y][x] = w;
		}
		for(int i=1; i<=n; i++) d[i] = {INT_MAX, -1};
	  priority_queue<item, vector<item>, greater<item> > q;
		q.push({0,1});
		d[1] = {0,-1};
		int xd=20;
		while(!q.empty()){
			g = q.top();
			u = g.Y;
			pc = g.X;
			q.pop();
			// for(auto i:adj[u]) printf("%d\n", i.X);
			for(auto j:adj[u]) {
				// if(!xd--) return 0;
				v = j.X;
				c = adj[u][v];
				// for(auto c:adj[u][v]) {
					// if(!xd--) return 0; 
					// printf("%d %d %d %d\n", u, v, pc+c, d[v].X);
				if( pc+c < d[v].X ) {
					d[v] = {pc+c, u};
					q.push({pc+c, v});
				} 						
				// }
			}
		}
		// if(gg==6) {
		// 	for(auto i:d){
		// 		printf("x= %d %d %d %d\n", i.X, *i.Y.begin(), *i.Y.rbegin(), i.Y.size());
		// 	}
		// 	for(auto i:adj){
		// 		for(auto j:i.Y) {
		// 			printf("y - %d %d ", i.X, j.X);
		// 			for(auto l:j.Y) printf("%d ", l);
		// 			printf("\n");
		// 		}
		// 	}
		// }
		if(d[n].Y==-1) printf("-1\n");
		else {
			adj.clear();
			stack<int> g;
			int xxx = d[n].Y;
			g.push(n);
			while(xxx != -1) {
				g.push(xxx);
				xxx = d[xxx].Y;
			}
			while(!g.empty()) printf("%d ", g.top()), g.pop();
			printf("\n");
		}
	}