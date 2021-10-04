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
unordered_map<int,unordered_map<int,set<int> > > adj;
unordered_map<int, set<int> > d;

int main(){
	int gg=100000;
	int t;
	scanf("%d", &t);
	for(int ig=1; ig<=t; ig++) {
		adj.clear();
		d.clear();
		scanf("%d %d", &n, &r);
		if(ig==gg)	printf("%d %d\n", n, r);
		for(int i=0; i<r; i++) {
			scanf("%d %d %d", &x, &y, &w);
			if(ig==gg) printf("%d %d %d\n", x,y,w);
			adj[x][y].insert(w);
			adj[y][x].insert(w);
		}
    priority_queue<item, vector<item>, greater<item> > q;
		q.push({0,1});
		d[1].insert(0);
		while(!q.empty()){
			g = q.top();
			u = g.Y;
			pc = g.X;
			q.pop();
			for(auto j:adj[u]) {
				v = j.X;
				for(auto c:adj[u][v]) {
					if( d.find(v)==d.end() || d[v].size()<2 || 
						(pc+c < *d[v].B && pc+c != *d[v].B && pc+c != *d[v].A) ) {
						if(ig==gg) printf("g - %d %d %d %d %d\n", q.size(), u, v, c, pc);
						if(d[v].size() > 1) d[v].erase(++d[v].A);
						d[v].insert(pc+c);
						q.push({pc+c, v});
					} 					
				}
			}
		}
		if(ig==gg) {
			for(auto i:d){
				printf("x= %d %d %d %d\n", i.X, *i.Y.begin(), *i.Y.rbegin(), i.Y.size());
			}
			for(auto i:adj){
				for(auto j:i.Y) {
					printf("y - %d %d ", i.X, j.X);
					for(auto l:j.Y) printf("%d ", l);
					printf("\n");
				}
			}
		}
	  printf("Case %d: %d\n", ig, *++d[n].A);
	}
}