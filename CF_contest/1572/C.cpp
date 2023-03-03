#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


int i, ix, t, n, m, k, p, q, gg, x, y, z;
vector<vector<int>> adj, ans_list; // adjacency list of graph
vector<int> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]){
            dfs(u);
        }
    }
    ans.push_back(v);
    // debug(ans);
}

bool topological_sort() {
    visited.assign(n, 0);
	ans_list.clear();    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
    		ans.clear();
            dfs(i);

			ans_list.push_back(ans);
			map<int,int> p;
		    for(int i=0; i<ans.size(); i++) p[ans[i]] = i;  
		    
		    for(auto i : ans) {
		    	for(auto ix:adj[i]) {
		    		if(p[ix] > p[i]) {
		    			return false;
		    		}
		    	}
		    }
		}
    }
    return true;
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		adj.clear();
		for(int i=0; i<n; i++) 
			adj.push_back(vector<int>()); 

		for(int i=0; i<n; i++) {
	    	scanf("%d", &x);
	    	adj[i].push_back(i);
	    	for(int ix=0; ix<x; ix++) {
	    		scanf("%d", &y);
	    		adj[i].pb(y-1);
	    	}
	    }

	    if(!topological_sort()) {
	    	cout << -1 << "\n";
	    	continue;
	    }

	    int c = 0;
	    for(auto ans : ans_list) {
	    	int tc = 0;
	    	for(int i=0; i<ans.size(); i++) {
	    		if(i<ans.size()-1 && ans[i+1] < ans[i]) tc++;
	    	} 
	    	c = max(c, tc);
	    }

	    cout << c + 1 << "\n";
	}
}