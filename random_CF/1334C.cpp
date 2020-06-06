#include <stdio.h>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// void update(vector<pair<int,int> > monsters, vector<int> bst, int si, int val){
// 	if(monsters[bst[si]] > )
// }

int main(){
	int n, t, i, h, d;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> bst(n);
		vector<pair<int,int> > monsters(n);
		int damage[n]={0};
		set<pair<int,int> > damage;
		int n;
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d %d", &h, &d), monsters.push_back(make_pair(h, d));
		for(i=n-1; i>=0; i--){
			if(damage[i]==0){
				int dmg = 0, tempI=i;
				if(damage[(tempI+1<n)?tempI+1:0]!=0){
					if(monsters[(tempI+1<n)?tempI+1:0].first <= monsters[tempI]) damage[i] = damage[(tempI+1<n)?tempI+1:0] + monsters[(tempI+1<n)?tempI+1:0].first;
					else damage[i] = monsters[tempI].second;
					continue; 
				}else{
					while(monsters[tempI].second >= monsters[(tempI+1<n)?tempI+1:0].first){
						dmg += monsters[(tempI+1<n)?tempI+1:0].first;
						tempI = (tempI+1<n)?tempI+1:0;
					}
					damage[i] = dmg + monsters[tempI].second;
				}
			}
		}
		for(int i=0; i<n; i++) printf("%d ", damage[i]);
	} 
}