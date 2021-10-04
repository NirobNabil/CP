#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define PUSH(x) if(!visited[x]) { q.push_back(x); visited[x]=1; }
#define item pair<pair<int,int>,int>
#define X first
#define Y second
int k, n, m, x, p, l;
unordered_map<int,unordered_map<int,int> > adj;

int maximum = 0, below[100005], visited[100005], parent[100005];

int dfs(int x, int p) {
	parent[x]=p;
	if( adj[x].size()==1 && adj[x][p]==1) return 0;
	else {
		for(auto i:adj[x]){
			if(i.X!=p) below[i.X] += dfs(i.X, x)+1;
		}
	}
	return below[x];
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(below, 0, sizeof(below));
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		adj.clear();
		scanf("%d", &n);
		int x,y;
		for(int i=0; i<n-1; i++) {
			scanf("%d %d", &x, &y);
			adj[x][y]=1;
			adj[y][x]=1;
		}
		dfs(x,x);
		int min = INT_MAX, ans, cmax;
		for(int x=0; x<n; x++) {
			cmax=0;
			for(auto i:adj[x]) {
				if(i.X!=parent[x]) cmax=max(below[i.X], cmax);
			}
			cmax = max(n-below[x]-1, cmax);
			if(cmax<min) min=cmax, ans=x;
		}
	  printf("%d\n", ans);
	}
}