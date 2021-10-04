#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>

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


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define CEIL(x,y) (x%y ? (x/y + 1) : x/y)

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


int main(){
	ll i, ix, t, n, m, k, p, h, q, gg, x, y, z;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &h, &p);
	    ll ans = 0, ch = 0, rp = 0, pp = 0, processed;
	    for(int i=0; i<h; i++) {
	    	pp += 1 << i;
	    } 
	    // while(ch != h) {
	    // 	rp += (1<<ch);
	    // 	ans += CEIL(rp , p);
	    // 	// debug("b",rp);
	    // 	if( rp%p && (1<<ch) > p) {
		   //  	rp = 0 - (p - (rp%p));
	    // 	}else { rp = 0; }
	    // 	debug(rp, ans);
	    // 	ch ++;
	    rp = 1;
	    while(pp > 0) {
	    	rp = min(pp, rp);
	    	ans += max(rp / p, (ll)1);
	    	if(rp > p) {
	    		processed = (rp/p) * p;
	    	}else processed = rp;
	    	rp -= processed;
	    	rp += (processed * 2); 
	    	pp -= processed;
	    	// debug(pp, rp, processed);
	    }
	    cout << ans << "\n";
	}
}