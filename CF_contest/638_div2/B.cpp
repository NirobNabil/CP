#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int ans[n*k+1];
		for(int i=1; i<n*k; i+=k) scanf("%d", &ans[i]);
		
	}
	scanf("%d", &t);
}

// 		int n, k;
// 		scanf("%d %d", &n, &k);
// 		list<int> in;
// 		set<int> distincts;
// 		for(int i=0; i<n; i++){
// 			int temp;
// 			scanf("%d", &temp);
// 			in.push_back(temp);
// 			distincts.insert(temp);
// 		}
// 		// for(int i=1; i<=n; i++) if(dis[i]==1) distincts.push_back(i);
// 		if(distincts.size()>k) printf("-1\n");
// 		else{
// 			// vector<int> ans;
// 			set<int> t_distincts = distincts;
// 			auto ix=in.begin(), i=in.begin();
// 			for(auto xx=1; xx<k; xx++, ix++){
// 				if(ix==in.end()) printf("-1\n");
// 				else t_distincts.erase(*ix);	
// 			}
// 			for(; ix!=in.end(); ix++, i++){
// 				t_distincts.erase(*ix);
// 				if(++ix != in.end()) in.insert(ix--, t_distincts.begin(), t_distincts.end());
// 				else in.push_back()
// 				t_distincts.insert(*i);
// 			} 
// 		}
// 		for(auto i=in.begin(); i!=in.end(); i++){
// 			cout << *i << " ";
// 		}