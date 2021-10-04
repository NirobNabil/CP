#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define PUSH(x) if(!visited[x]) { q.push_back(x); visited[x]=1; }
#define item pair<pair<int,int>,int>
#define X first
#define Y second
int k, n, m, x, p, l;
unordered_map<int,unordered_map<int,int> > adj;

int cats[100005], ans;

void dfs(int x, int p, int c) {
	if(cats[x]) c++;
	else c=0;
	if(c>m) return;
	else if( adj[x].size()==1 && adj[x][p]==1 ) {ans++; return;}
	else {
		for(auto i:adj[x]){
			if(i.X!=p) dfs(i.X, x, c);
		}
	}
	return;
}


int main(){
	ans=0;
	adj.clear();
	scanf("%d %d", &n, &m);
	int x,y;
	for(int i=1; i<=n; i++) scanf("%d", &cats[i]);
	for(int i=0; i<n-1; i++) {
		scanf("%d %d", &x, &y);
		adj[x][y]=1;
		adj[y][x]=1;
	}
	dfs(1,1,0);
  printf("%d\n", ans);
}