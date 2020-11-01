#include <bits/stdc++.h>
using namespace std;
#define ll long long int
char names[100][105];
unordered_map<char,int> in_deg(30);
unordered_map<char, unordered_map<char,int> > adj;


int sett(char x, char y) {
	if(adj.find(y)!=adj.end() && adj[y].find(x)!=adj[y].end()) return 0;
	if(adj.find(x)!=adj.end() && adj[x].find(y)!=adj[x].end()) return 1;
	adj[x][y] = 1;
	if(in_deg.find(x-'a')==in_deg.end()) in_deg[x-'a']=0;
	in_deg[y-'a']++;
	return 1;
}

int check(int i1, int i2, int i) {
	if(names[i1][i] == '\0' && names[i2][i] != '\0') return 1;
	else if(names[i1][i] != '\0' && names[i2][i] == '\0') return 0;
	if(names[i1][i] != names[i2][i]) return sett(names[i1][i], names[i2][i]);
	else return check(i1, i2, i+1); 
}

vector<int> top_sort(unordered_map<char, int> in_deg, unordered_map<char, unordered_map<char,int> > adj){
	queue<int> q;
	int visited[27]={0};
	vector<int> ans;
	int v,xd=20, ix, gg;
	while(in_deg.size()  && xd--) {
		gg=0;
		for(auto i:in_deg) {
			if(i.second==0) {
				q.push(i.first);
				in_deg.erase(i.first);
				visited[i.first]=1;
				gg=1;
				break;
			}
		}
		if(gg==0) {
			std::vector<int> lll;
			lll.push_back(-1);
			return lll;
		}
		while(!q.empty()) {
			v = q.front();
			q.pop();
			ans.push_back(v);
			for(auto i:adj[v+'a']) {
				ix = i.first-'a';
				if(!visited[ix]) in_deg[ix]--;
				if(!in_deg[ix] && !visited[ix]) q.push(ix), visited[ix]=1, in_deg.erase(ix);
			}
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%s", names[i]);
	for(int i=0; i<n-1; i++) {
		if(!check(i,i+1,0)) {
			printf("Impossible\n");
			return 0;
		}
	}
	vector<int> gg = top_sort(in_deg, adj);
	if(gg.begin()!=gg.end() && gg[0]==-1) {
		printf("Impossible\n");
		return 0;	
	}
	for(auto i:gg) printf("%c", i+'a'); 
	for(int i=0; i<26; i++) {
		if( find(gg.begin(), gg.end(), i) != gg.end() ) continue;
		printf("%c", i+'a');
	} 
	printf("\n");
}