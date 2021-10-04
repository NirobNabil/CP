#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 10000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<pair<int,int> > stones, pstones(S1);
int n;

ll checkdist(int i, int ix) {
	return (stones[ix].X - stones[i].X)*(stones[ix].X - stones[i].X) 
				+ (stones[ix].Y - stones[i].Y)*(stones[ix].Y - stones[i].Y);
}


int main(){

	int i, ix, t, x, y, tc = 0;
	while(scanf("%d", &n) && n != 0 && ++tc){
		stones.clear();
		for(int i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			stones.push_back({x,y});
		}
		ll d[n][n], p[n][n];

		for(int i=0; i<n; i++) {
			for(int ix=0; ix<n; ix++) {
				d[i][ix] = checkdist(i, ix);
				d[ix][i] = d[i][ix];
				p[i][ix] = -1;
			} 
		}

		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]) );
					// printf("%d %d %d %f\n", i, j, k, d[i][j]);
				} 
			}
		}

		printf( "Scenario #%d\nFrog Distance = %.3lf\n\n", tc, sqrt(d[0][1]) );

	}

}