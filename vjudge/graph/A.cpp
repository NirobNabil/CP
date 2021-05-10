#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

unordered_map<int, vector<int> > lang, empl;
int rnk[S1], parent[S1];
bool processed[S1]; 
queue<int> q;
int i, ix, x, y, t, n, m;

void printempl() {
	for(int i=1; i<=n; i++) {
		printf("%d - ", i);
		for(auto ix:empl[i]) {
			printf("%d ", ix);
		}
		printf("\n");
	}
}


int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
  parent[v] = v;
  rnk[v] = 0;
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
  }
}

void bfs(int i) {
	if(processed[i]) return;
	processed[i] = 1;
	for(auto l:empl[i]) {
		for(auto e:lang[l]) {
			if(find_set(e) != find_set(i)) {
				q.push(e);
				union_sets(i, e);
			}
		}
	}
}


int main(){
	int cost=0;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		while(x--) {
			scanf("%d", &y);
			empl[i].push_back(y);
			lang[y].push_back(i);
		} 
	}
	for(int i=1; i<=n; i++) {
		make_set(i);
	}
	for(int i=1; i<=n; i++) {
		if(empl[i].size() == 0) empl[i].push_back(y), cost++, lang[y].push_back(i);
	}
	for(int i=1; i<=n; i++) {
		if(i>1 && processed[i]==0) {
			union_sets(i,1);
			cost++;
		}
		bfs(i);
		while(q.size()) {
			bfs(q.front());
			q.pop();
		}
	}
	// int gp = find_set(1);
	// for(int i=2; i<=n; i++)  {
	// 	if(find_set(i) != gp) {
	// 		union_sets(i,gp);
	// 		cost++;
	// 	}
	// }
	printf("%d\n", cost);
}

/*
8 7
0 - 1
3 1 2 3 - 2
1 1 - 3
2 5 4 - 4
2 6 7 - 5
1 3 - 6
2 7 4 - 7
1 1 - 8
*/	