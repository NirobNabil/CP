#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<vector<ll> > grid(S1);
vector<pair<ll,ll> > vi;
vector<pair<ll,ll> > vv;
vector<ll > vm;

ll chk(ll i, bool d) {
	if(d ? i==vv.size()-1 : i==0) return vm[i];
	ll nxt = d ? chk(i+1,d) : chk(i-1,d);
	if(vm[i] > vv[i].X+nxt) {
		vm[i] = vv[i].X+nxt;
	}
	return vm[i];
}

int main(){
	ll i, ix, t, n, a[S1];
	scanf("%lld", &n);
	for(int i=0; i<n; i++) {
		for(int ix=0; ix<n; ix++) {
			scanf("%lld,", &t);
			grid[ix].push_back(t);
		} 
	}

	for(ll i=n-1; i>=0; i--) {
		vi.clear();
		vv.clear();
		vm.clear();
		if(i==n-1) {
			vm.push_back(grid[n-1][n-1]);
			continue;
		}
		for(ll ix=n-1; ix>i; ix--) {
			vi.push_back({i,ix});
			vv.push_back({grid[i][ix],grid[i+1][ix]});
			vm.push_back(grid[i][ix]+grid[i+1][ix]);
		}
		for(ll ix=i; ix<n; ix++) {
			vi.push_back({ix,i});
			if(ix==i) {
				vv.push_back({grid[i][i],INT_MAX});
				vm.push_back(INT_MAX);
			} else {
				vv.push_back({grid[ix][i],grid[ix][i+1]});
				vm.push_back(grid[ix][i]+grid[ix][i+1]);
			}
		}
		chk(vv.size()/2,1);
		chk(vv.size()/2,0);
		for(int i=0; i<vi.size(); i++)  {
			grid[vi[i].X][vi[i].Y] = vm[i];
		}
	} 
	printf("%lld\n", grid[0][0]);
}