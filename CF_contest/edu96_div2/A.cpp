#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int chk(int a, int x){
	if(x==7) {
		if(a%x==0) { printf("%d ", a/x); return 1; }
	}
	for(int i=0; i*x<=n; i++) {
		if(chk(a-i*x, x+=2)) { printf("%d ", i), return 1 };
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if(chk(n, 3)) continue;
		else 
	}
}


vector<int> adj[n];
bool visited[n];
void dfs(x) {
	if(visited[x]) return;
	visited[x] = true;
	for(auto i:adj[x]) {
		//do your thing here
		dfs(x);
	}
	return;
}