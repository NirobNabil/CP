#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pp pair<int,int>

struct cmp{
    bool operator()(const pp &a, const pp &b){
        return a.x < b.x;
     }
};

int main(){
	int n, t;
	scanf("%d", &n);
	vector<set<pp> > occurences(27);
	occurences[1].insert(make_pair(1,1));
	for(int i=0; i<n; i++){
		scanf("%d", &t);
		//occurences[t].insert(*occurences[t].lower_bound(i)+1);
		set<pair<int,int> >::iterator gg = occurences[t].lowerbound(i);
		int x = gg->y;
		occurences[t].insert(make_pair(i, (occurences[t].size()>0)?x+1:1 ));
	}
	//printf("%d\n", *(occurences[1].lower_bound(7)));
}