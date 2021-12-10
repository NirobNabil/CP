#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


// 0 = white, 1 = blue, 2 = red
int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<vector<ll> > dp(n, vector<ll>(3));
	
	    for(int i=n-1; i>=0; i--) {
			if(n-i < 3) {
			    dp[i][0] = 1;
			    dp[i][2] = 1;
				continue;
			}

			dp[i][0] = dp[i+1][2] + dp[i+2][2];
			dp[i][2] = dp[i+1][0] + dp[i+2][0];
	    } 
	    
    	cout << dp[0][0] + dp[0][2] << "\n";
    }
}