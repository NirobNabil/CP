#include <bits/stdc++.h>
using namespace std;
#define ll long long int

map<int, map<int, int> > adj;
map<int, int> in_deg;

vector<int> top_sort(map<int, int> in_deg, map<int, map<int,int> > adj){
	priority_queue<int, vector<int>, greater<int> > q;
	int visited[10005]={0};
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
	int n,m,x,y;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) in_deg[i]=0;
	for(int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		in_deg[y]++;
	}
	// for(auto i:in_deg) printf("%d %d\n", i.first, i.second);
	std::vector<int> v = top_sort(in_deg, adj);
	if(v.begin() != v.end() && v[0]==-1) {
		printf("Sandro fails.\n");
		return 0;
	}
	for(auto i:v) printf("%d ", i);
	printf("\n");
}