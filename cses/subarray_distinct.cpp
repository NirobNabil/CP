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
#define S1 500000

#ifdef MONKE
#include <bits/debug.h>
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


unordered_map<int,int> v;
int a[S1];
int i, ix=0, t, n, m, k, p, q, gg, x, y, z;
ll ans = 0;
int sz = 0;

int main(){
	scanf("%d %d", &n, &k);
	v.reserve(n+9);
	for(int i=0; i<n; i++) {
  	scanf("%d", &a[i]);
  }
  for(int i=0; i<n; i++) {
		while(1) {
			if(ix >= n) break;
			if(v[a[ix]] == 0) {
				if(sz == k) break;
				sz++;
			}
			v[a[ix]]++;
			ix++;
		}
		v[a[i]]--;
		if(v[a[i]] == 0) sz--;	
		ans += ix - i;
	}
	printf("%lld\n", ans); 
}