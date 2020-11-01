#include <bits/stdc++.h>
#define MIN(a,b) ((a>b)?b:a)
#define x first
#define y second
using namespace std;

int val[200001], below[200001];

int dfs(set<pair<int,int> > &leafs, set<int> *adj, int u, int from, int cost){
	if(adj[u].size()==1 && u!=1){
		//printf("for %d\n", u);
		leafs.insert(make_pair(cost - below[u], u));
		return 1;
	}
	for(auto v : adj[u]){
		if(v==from) continue;
		val[v] = cost+1;
		below[u] += dfs(leafs, adj, v, u, cost+1);
		//printf("x- %d %d %d\n", u, v, below[u]);
	}
	return below[u]+1;
}

int main(){
	int n, k, u, v, min_node = 0;
	long long int total=0;
	scanf("%d %d", &n, &k); 
	set<int> adj[n+1];
	set<pair<int,int> > leafs;
	for(int i=1; i<n; i++){
		scanf("%d %d", &u, &v);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(leafs, adj, 1, 1, 0);
	while(k--){
		//for(auto i : leafs) cout << i.x << " " << i.y << endl;
	 	v = (--leafs.end())->y;
	 	total += val[v] - below[v];
	 	//cout << total << endl << endl;
	 	min_node = *(adj[v].begin());
	 	adj[min_node].erase(v);
	 	if(adj[min_node].size()==1) leafs.insert(make_pair(val[min_node]-below[min_node], min_node));
	 	leafs.erase(make_pair(val[v]-below[v], v));
	}
	printf("%lld\n", total);
}