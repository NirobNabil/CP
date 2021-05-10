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

int coupons[7] = {10, 60, 280, 880, 1980, 3280, 6480};
int price[7] = {1, 6, 28, 88, 198, 328, 648};
int special[7] = {8, 18, 28, 58, 128, 198, 388};
int dp[257][2009];

int chk(int first, int n) {
	if(dp[first][n]) return dp[first][n];
	if(n<0) return INT_MIN;
	for(int i=0; i<7 && n-price[i] >= 0; i++) {
		if(1<<i & first) {
			dp[first][n] = max(dp[first][n], coupons[i] + chk(first, n-price[i]));
		} else {
			dp[first][n] = max(dp[first][n], coupons[i] + special[i] + chk(first | 1<<i, n-price[i]));
		}
	}
	return dp[first][n];
}

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &n);
	cout << chk(0, n) << endl;
}