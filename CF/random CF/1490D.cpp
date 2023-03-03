#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<int> level(S1);
int i, ix, t, n, a[S1], m;

void make_tree(int x, int s, int e, int l) {
	// cerr << x << " " << s << " " << e << " " << l << endl;
	if(s==e) return;
	level[x] = l;
	for(i=x+1, m=x+1; i<e; i++) if(a[i]>a[m]) m=i;
	make_tree(m, x+1, e, l+1);
	for(i=s, m=s; i<x; i++) 		if(a[i]>a[m]) m=i;
	make_tree(m, s, i, l+1);
}

int main(){
	scanf("%d", &t);
	while(t--){
		level.clear();
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		for(i=0, m=0; i<n; i++) if(a[i]>a[m]) m=i;
		make_tree(m, 0, n, 0);
		for(int i=0; i<n; i++) printf("%d ", level[i]);
		printf("\n");
	}
}