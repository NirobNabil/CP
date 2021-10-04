#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)

#define X first
#define Y second
#define A begin
#define B end
#define S1 109

vector<int> a(S1);
map<bitset<100>, int> dp;
bitset<100> pm(1);

int chksq(bitset<100> mask, int i) {
	if( dp[mask][i] ) return dp[mask][i];
	int s1=0, s2=0;
	for(int i=0; i<n; i++) {
		if(mask & pm << i ) s1 += a[i];
		else s2 += a[i];
	}
	if(s2 == s1) return 1;
	int p = 0;
	for(i++; i<n; i++) {
		p += chksq(mask | pm<<i, i);
	}
	return p;
}

int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    
	}
}