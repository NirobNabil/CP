#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		int n, m, u, v, w;
		scanf("%d %d", &n, &m);
		unsigned int d[n+2];
		memset(d, 0b11111111, sizeof(d));
		unordered_map<int, int> adj[n+5];
		adj[1][1] = 0;
		for(int i=0; i<m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			// if(ix==45) printf("%d %d %d\n", u, v, w);
			adj[u][v] = (adj[u].find(v)!=adj[u].end())?min(adj[u][v], w):w;
			adj[v][u] = (adj[v].find(u)!=adj[v].end())?min(adj[v][u], w):w;
		}
		// for(int iy=1; iy<=n; iy++) {
		// 	// cout << adj[iy].size() << endl;
		// 	for(auto i:adj[iy]) {
		// 		cout << iy << " " << i.X << " " << i.Y << endl;
		// 	}
		// }
		priority_queue<pair<int, int> > q;
		q.push({0,1});
		d[1] = 0;
		int r=0;
		while(q.size()) {
			int qt = q.top().Y;
			q.pop();
			for(auto i:adj[qt]) {
				if(d[i.X] > d[qt] + adj[qt][i.X]) {
					d[i.X] = d[qt] + adj[qt][i.X];
					q.push({d[i.X], i.X});
				}
				// cout << i.X << " - " << adj[i.X].size() << endl;
			}
			// cout << q.top().X << " " << q.top().Y << endl;
			// r++;
		}
		if(d[n]==0xFFFFFFFF) printf("Case %d: Impossible\n", ix);
		else printf("Case %d: %u\n", ix, d[n]);
	}
}