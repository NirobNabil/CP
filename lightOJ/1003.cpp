// #include "bits/stdc++.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long int

unordered_map<string, unordered_set<string> > c;
unordered_set<string> visited;
bool xd=false;
void dfs(string a) {
	if(c.find(a) == c.end()) return;
	if(visited.find(a) != visited.end()){ xd=true; return;}
	visited.insert(a);
	for(auto p:c[a]){ if(xd) break; dfs(p); }
	c.erase(a);
	return;
}

int main(){
	ios_base::sync_with_stdio(1);
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		xd =false;
		c.clear();
		visited.clear();
		int n;
		string a, b;
		bool gg=false;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			cin >> a >> b;
			c[b].insert(a);
		}
		while(c.size()) {
			dfs((*c.begin()).first);
		}
	  printf("Case %d: %s\n", ix, (xd==false?"Yes":"No"));
	}
}