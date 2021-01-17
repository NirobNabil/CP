#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


int main(){
	int i, ix, t, n, a[S1];
	float x;
	scanf("%d", &t);
	while(t--){
		vector<float> g;
		scanf("%d %f", &n, &x);
		rep(i, 0, n) scanf("%d", &a[i]);
		rep(i,0,n) g.push_back((float)a[i]);
		for(int i=n-1; i>0; i--) {
			if( (int)ceil((g[i]+g[i-1])/x) < (int)ceil(g[i]/x) + (int)ceil(g[i-1]/x) ) {
				g[i-1]=g[i]+g[i-1];
				g[i]=0;				
			} 
		}
		int beauty=0;
		for(int i=0; i<n; i++) {
			beauty += (int)ceil(g[i]/x);
		}
		printf("%d ", beauty);

		g.clear();
		rep(i,0,n) g.push_back((float)a[i]);
		for(int i=n-1; i>0; i--) {
			if( (int)ceil((g[i]+g[i-1])/x) > (int)ceil(g[i]/x) + (int)ceil(g[i-1]/x) ) {
				g[i-1]=g[i]+g[i-1];
				g[i]=0;				
			} 
		}
		beauty=0;
		for(int i=0; i<n; i++) {
			beauty += (int)ceil(g[i]/x);
		}
		printf("%d\n", beauty);
	}
}