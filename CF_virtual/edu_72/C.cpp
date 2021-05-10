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

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		//vx r-b    vy b-r
		vector<int> vx(n+9), vy(n+9);
		rep(i, 0, n*2) scanf("%d", &a[i]);
	
		ll vxsum = 0;
		for(int i=0; i<n; i++) vxsum += a[i]==1?1:-1;
		printf("%d\n", vxsum);
		vx[0] = vxsum;
		for(int i=n-1; i>=0; i--) vx[n-i] = (a[i]==1?-1:1) + (i<n-1?vx[n-i-1]:vxsum);
		for(int i=0; i<=n; i++) printf("%d ", vx[i]);
		printf("\n");

		ll vysum = 0;
		for(int i=n; i<n*2; i++) vysum += a[i]==1?-1:1;
		vy[0] = vysum;
		for(int i=n; i<n*2; i++) vy[i-n+1] = (a[i]==1?1:-1) + (i>n?vy[i-n]:vysum);
		for(int i=0; i<=n; i++) printf("%d ", vy[i]);
		printf("\n");
		printf("%lld %lld\n", vxsum, vysum);
	
		map<int,int> vxm;
		for(int i=n; i>=0; i--) vxm[vx[i]] = i;

		ll ans = LONG_MAX;
		for(int i=0; i<=n; i++) {
			printf("%d %d %d\n", i, vxm.find(vy[i])!=vxm.end()?vxm[vy[i]]:INT_MAX, 0-vy[i] );
			ans = min(ans, (ll)(vxm.find(vy[i])!=vxm.end()?vxm[vy[i]]:INT_MAX) +i);
		}
		printf("%d\n", ans);
	}
}