#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int haswater[S1], parent[S1], node[S1];
int* nxt[S1];
map<int, set<int> > tree;

int fill(int i) {
	if(haswater[i]) return 0;

	int* nx = nxt[i];
	haswater[*nx] = 1;
	tree[parent[*nx]].erase(*nx);
	
	if(tree[parent[*nx]].size() == 0) {
		*nx = parent[*nx];
	}
	else {
		*nx = *nxt[*tree[parent[*nx]].A()];
	}

	return 1;
}


void dfs(int n) {
	tree[n].erase(parent[n]);
	node[n] = n;
	nxt[n] = &node[n];
	for(auto i:tree[n]) {
		parent[i] = n;
		dfs(i);
	}
	if(tree[n].size())
		nxt[n] = nxt[*tree[n].begin()];
}

int main(){
	int i, ix, t, n, x, y, q, c, u;
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++) {
		scanf("%d", &n);
		tree.clear();
		memset(haswater, 0, sizeof(haswater));
		memset(parent, 0, sizeof(parent));
		memset(node, 0, sizeof(node));
		vector<pair<int,int> > list;
		for(int i=0; i<n-1; i++) {
			scanf("%d %d", &x, &y);
			tree[x].insert(y);
			tree[y].insert(x);
		}

		dfs(1);

		scanf("%d", &q);
		printf("Case %d:\n", tc);
		while(q--) {
			scanf("%d", &c);
			if(c == 1) {
				scanf("%d %d", &u, &x);
				while(x--) {
					if(haswater[u]) break;
					fill(u);
				}
			}else {
				scanf("%d", &u);
				printf("%d\n", haswater[u]);
			}
		} 
	}
}