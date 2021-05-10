#define graph map<int,map<int,bool> >
struct w_pair{
	int w, a, b;
};
#define nodelist unordered_map<int, int>
#define adjlist_w vector<w_pair >
#define adjlist vector<pair<int, int> >
#define node int
#define S1 10006

vector<bool> vis(S1);
template<typename lambda>
void dfs(graph &g, node n, lambda f) {
	vis[n] = 1;

	// add logic here
	f(n);

	for(auto i:g[n]) {
		if(vis[i.X]) dfs(g, i.X);
	}
}

//only works for rooted tree
void toposort(vector<int> &list, graph &g, int root) {
	auto ts_logic = [&](node n){
		list.push_back(n);
	}

	dfs(g, 0, ts_logic);
}

// DSU utils
int find_set(node v, nodelist &p) {
    if(v == p[v]) {
        return v;
    }else return p[v] = find_set(p[v], p);
}

void union_sets(node a, node b, nodelist &p, nodelist &depth) {
    a = find_set(a, p);
    b = find_set(b, p);
    if(a != b) {
        if(depth[a] < depth[b]) 
            swap(a,b);
        p[b] = a;
        if(depth[a] == depth[b])
            depth[a]++;
    }
}

void make_set(node v, nodelist &p, nodelist &depth) {
  if(p[v] && find_set(v, p) != v) return;
  else {
      p[v] = v;
      depth[v] = 1;
  }
}

void make_union(node v1, node v2, nodelist &p, nodelist &depth) {
  union_sets(v1, v2, p, depth);
}


// MST
void kruskal(int n, adjlist_w &adj, graph &mst) {
  n++;
  sort(adj.A(), adj.B());
  nodelist p(n);
  for(int i=0; i<n; i++) p[i] = i;
  nodelist depth(n+99, 0);
  int a, b, w;
  for(int i=0; i<adj.size(); i++)  {
      a = adj[i].Y.X;  b = adj[i].Y.Y;  w = adj[i].X;
      if(find_set(a, p) == find_set(b, p)) continue;
      printf("xx %d %d\n", a, b);
      mst[a][b] = w;
      mst[b][a] = w;
      make_union(a, b, p, depth);
  }
}