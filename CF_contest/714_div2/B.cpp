#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

ll dp[1000000];
ll MOD = 1000000000 + 7;

ll chk(int i, int d) {
	if(d < 10 && i==0 ) return 1;
	else if(d < 9 && i==1) return 1;

	if(dp[d]) return dp[d];

	dp[d] = ( chk(0, d - 10) % MOD + chk(0, d - 9) % MOD ) % MOD; 
	return dp[d];
}

int main(){
	int i, ix, t, n, d, x, y, z;
	scanf("%d", &t);
	while(t--) {
		char a[20];
		scanf("%d %d", &n, &d);
		sprintf(a, "%d", n);
		int len = strlen(a);
		int ans = 0;
		for(int i=0; i<len; i++) {
			ans = (ans + chk(0, d+(a[i]-'0')) ) % MOD;
		}
		cout << ans << "\n";
	}
}