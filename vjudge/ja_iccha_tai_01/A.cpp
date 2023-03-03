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
#define S1 100000

ll i, ix, t, m, r, k, q, gg, x, y, z;
string s;
map<char, ll> n, per;
map<char, ll> p;

ll chk(ll c) {
	ll cost = 0;
	for(auto i:per) {
		cost +=max((ll)0, p[i.X] * ( per[i.X] * c  - n[i.X] ));
		if(cost > r) return 0;
	}
	return 1;
}

ll bs(ll l, ll h) {
	ll mid;
	while( l+1 < h ) {
		mid = (l+h) / 2;
		// cerr << "gg" << endl;
		// cout << mid << endl;
		if( chk(mid) ) l = mid;
		else h = mid; 
	}

	if(chk(h)) return h;
	else return l;
}

int main(){
	
	cin >> s;
	scanf("%lld %lld %lld", &n['B'], &n['S'], &n['C']);
	cin >> p['B'] >> p['S'] >> p['C'];
  cin >> r; 
  ll c = 0;

	for(int i=0; i<s.size(); i++) {
		per[s[i]]++;
	} 

	printf("%lld\n", bs(0, (ll)10e14));
	
}