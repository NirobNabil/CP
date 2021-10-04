#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

const ll M = 1000000007;

int i, ix, t, n, k, x, y, z;
ll dp[1009][1009];

ll go(int r, int k) {

	if( k == 1 || r <= 0 || r > n ) dp[r][k] = 1;
	if( dp[r][k] ) return dp[r][k];

	dp[r][k] = 1;

	dp[r][k] = ( go(r-1, k) + go(n-r, k-1) ) % M;

	return dp[r][k];
}


int main(){
	scanf("%d", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &k);
		printf("%d\n", go(n, k));

	}
}