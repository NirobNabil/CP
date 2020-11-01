#include "bits/stdc++.h"
using namespace std;
#define ll long long int

unordered_map<int, pair<int, int> > cities;
unordered_map<int, vector<int> > nodes;
int flag = 0;

pair<int,int> dfs(int node, int parent) {
	int g,b,total=0;
	pair<int, int> temp, t_temp = make_pair(0,0);
	if(nodes[node].size()==1 && nodes[node][0]==parent){
		g = (cities[node].first + cities[node].second)/2;
		b = (cities[node].first - cities[node].second)/2;
		// printf("%d %d %d\n", node, g, b);
		if(g<0 || b<0 || g+b!=cities[node].first) {
			flag=1;
			return make_pair(0,0);
		}
		return make_pair(g,b);	
	}
	for(auto i:nodes[node]){
		if(i==parent) continue;
		temp = dfs(i, node);
		total += temp.first + temp.second;
		t_temp.first += temp.first;
		t_temp.second += temp.second;
	}
	g = (total+cities[node].first + cities[node].second)/2;
	b = (total+cities[node].first - cities[node].second)/2;
	if(g<0 || b<0) {
		flag=1;
		return make_pair(0,0);
	}
	// printf("%d %d %d - %d %d\n", node, g, b, t_temp.first, t_temp.second);
	if(g>=t_temp.first && t_temp.second==(b+g-cities[node].first)-t_temp.first) return make_pair(g,b);
	else {
		flag=1;
		return make_pair(0,0);
	}
}

int main(){
	int t, n, m, a, b;
	scanf("%d", &t);
	while(t--){
		cities.clear();
		nodes.clear();
		flag=0;
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++) scanf("%d", &cities[i].first);
		for(int i=1; i<=n; i++) scanf("%d", &cities[i].second);
		// if(t==9936){
		// 	for(int i=1; i<=n; i++) printf("%d ", cities[i].first);
		// 	printf("\n");
		// 	for(int i=1; i<=n; i++) printf("%d ", cities[i].second);	
		// 	printf("\n");
		// }	
		for(int i=1; i<n; i++) {
			scanf("%d %d", &a, &b);
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		if(n==1) {
			// printf("%d %d\n", cities[0].first, cities[0].second);
			if(cities[1].first >= abs(cities[1].second)) flag=0;
			else flag=1;	
		}
		else dfs(1,0);
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}