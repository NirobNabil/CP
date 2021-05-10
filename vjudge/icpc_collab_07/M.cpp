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


int main(){
	double n, ans = 0, prob = 1.0/20.0;
	scanf("%lf", &n);
	for(int i=1; i<n; i++) {
		ans += (1 - prob) * 10.0;
		ans += prob * 20.0;
	} 
	printf("%.4lf\n", ans);
}