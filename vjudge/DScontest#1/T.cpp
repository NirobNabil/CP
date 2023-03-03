#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

map<int, map<int, int> > adj, adj_u;
map<int, int> in_deg;

vector<int> top_sort(map<int, int> in_deg, map<int, map<int,int> > adj){
	priority_queue<int, vector<int>, greater<int> > q;
	int visited[200009]={0};
	vector<int> ans;
	int v, ix, gg, xd=20;
	while(in_deg.size() && xd--) {
		gg=INT_MAX;
		std::vector<int> to_erase;
		for(auto i:in_deg) {
			// printf("%d ", i.first);
			if(i.second==0) {
				q.push(i.first); to_erase.push_back(i.first); gg=0; visited[i.first]=1;
			}
		}
		for(auto i:to_erase) in_deg.erase(i);
		// printf("\n");
		if(gg==INT_MAX) {
			std::vector<int> lll;
			lll.push_back(-1);
			return lll;
		}
		while(!q.empty()) {
			v = q.top();
			q.pop();
			ans.push_back(v);
			for(auto i:adj[v]) {
				ix = i.first;
				if(!visited[ix]) in_deg[ix]--;
				if(!in_deg[ix] && !visited[ix]) q.push(ix), visited[ix]=1, in_deg.erase(ix);
			}
		}
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		adj.clear();
		adj_u.clear();
		in_deg.clear();
		int n,m,x,y,g;
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++) in_deg[i]=0;
		for(int i=0; i<m; i++) {
			scanf("%d %d %d", &g, &x, &y);
			if(g) {
				adj[x][y] = 1;
				in_deg[y]++;
			}else {
				adj_u[x][y] = 1;
			}
		}
		vector<pair<int, int> > edges;
		vector<int> v = top_sort(in_deg, adj);
		map<int, int> index;
		if(v.size()==1 && v[0]==-1) {
			printf("NO\n");
			continue;
		}else printf("YES\n");
		for(int i=0; i<v.size(); i++) {
			index[v[i]] = i;
		} 
		for(auto i:adj_u) {
			for(auto ix:i.Y) {
				if(index[i.X]>index[ix.X]) printf("%d %d\n", ix.X,i.X);
				else printf("%d %d\n", i.X,ix.X);
			}
		}
		for(auto i:adj){
			for(auto ix:i.Y) {
				printf("%d %d\n", i.X, ix.X);
			}
		}
	}
}