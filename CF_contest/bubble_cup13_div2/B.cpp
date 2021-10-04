#include "bits/stdc++.h"
using namespace std;
#define ll long long int

unordered_map<int, unordered_map<int, int> > adj;
int n, m, f, a, d;
unordered_map<int, bool> t_f, t_a;
int check(int i){
	if(i>n) return 0;
	t_f[i]=true;
	// printf("in %d\n", i);
	// printf("%d\n", adj[i].size());
	// printf("adj[%d][%d]=%d\n", i, adj[i], x.second);
	int gg = INT_MAX, d_n=INT_MAX, t=-1, pass=0;
	for(auto x:adj[i]) {
		// printf("t_a[%d]=%d\n", x.first, t_a[x.first]);
		if(t_a[x.first]) continue;
		pass=1;
		// printf("adj[%d][%d]=%d\n", i, x.first, x.second);
		t_a[x.first] = true;
		t = check(i+1);
		// printf("%d-t=%d\n", i,t);
		if(t!=-1) {
			gg = min(gg, t);
			d_n = min( d_n, max(gg, x.second));
			// printf("dn=%d\n", d_n);	
		}
		t_a[x.first] = false;
	}
	t_f[i] = false;
	// printf("out %d\n", i);
	if(!pass) return -1;
	else return d_n;
}

int main(){
	// int t;
	// scanf("%d", &t);
	// while(t--){
		adj.clear();
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++) {
			scanf("%d %d %d", &f, &a, &d);
			// printf("%d %d %d\n", f,a,d);
			adj[f].insert(make_pair(a,d));
		}
		int ans = check(1);
		printf("%d\n", ans==INT_MAX?-1:ans);
	// }
}