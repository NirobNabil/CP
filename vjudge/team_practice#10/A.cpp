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

// unordered_map<ll, unordered_map<ll, unordered_map<ll, ll> > > dt;
int dt[1<<11][109][109];
vector<ll> enrg, diff, scr;
ll i, ix, mt, mp;

ll check(ll mask, ll e, ll p) {

	if(p >= mp) return 0;

	// cerr << mask << " " << e << " " << p << "\n";
	ll score = 0;
	if(dt[mask][e][p] != -1) return dt[mask][e][p];
	// cout << bitset<10>(mask).to_string();
	// printf(" %lld %lld\n", e, p);	

	score = check(mask, e, p+1);

	if(e - diff[p] >= 0)
		score = max(scr[p] + check(mask, e-diff[p], p+1), score);

	for(int i=0; i<mt; i++) {
		if(mask & 1<<i) continue;
		score = max(check(mask | 1<<i, enrg[i], p), score);
	} 

	dt[mask][e][p] = score;
	return score;
}

int main(){
	// cerr << "gg" << endl;
	memset(dt, -1, sizeof(dt));
	scanf("%lld %lld", &mt, &mp);

	ll x;
	for(int i=0; i<mt; i++) scanf("%lld", &x), enrg.pb(x);
	for(int i=0; i<mp; i++) scanf("%lld", &x), diff.pb(x);
	for(int i=0; i<mp; i++) scanf("%lld", &x), scr.pb(x);

	cout << check(0, 0, 0);

	// printf("%d\n", dt[4][5][0]); 

}