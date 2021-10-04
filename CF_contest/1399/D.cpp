#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, n, h, hi, a[(int)2e5], e[(int)2e5];
	char s[(int)2e5];
	// list<int> b;
	set<int> is[2];
	vector<vector<int> > c;
	vector<int> d;
	scanf("%d", &t);
	while(t--){
		hi=0;
		c.clear();
		is[0].clear();
		is[1].clear();
		// b.clear();
		scanf("%d", &n);
		scanf("%s", s);
		memset(e, 0, sizeof(e));
		set<int>::iterator x, y;
		for(int i=0; i<n; i++) a[i]=(s[i]=='1'?1:0), a[i]==1?is[0].insert(i):is[1].insert(i);
		while(is[0].size() || is[1].size()){
			d.clear();
			if(is[1].begin() == is[1].end()) h=0;
			else if(is[0].begin() == is[0].end()) h=1;
			else if(*is[1].begin() < *is[0].begin()) h = 1;
			else h = 0;
			x= is[h].begin();
			while(x!=is[h].end()){
				y = is[!h].upper_bound(*x);
				d.push_back(*x);
				is[h].erase(x);
				if(y == is[!h].end()) break;
				else h = !h, x = y;
			}
			c.push_back(d);
		}
		printf("%d\n", c.size());
		for(int i=0; i<c.size(); i++) {
			for(auto ix:c[i]) a[ix]=i;
		}
		for(int i=0; i<n; i++) printf("%d ", a[i]+1);
		printf("\n");
	}
}