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

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


int main(){
	ll i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		map<ll, ll> a;
		ll s = 0;
		for(int i=0; i<n; i++) {
	    	scanf("%lld", &x);
	    	s += x;
	    	a[x]++;
	    }
	    ll dis  = s/n, c = 0;
	    if( s%n && (s%n)*2 == n ) dis = (s/n)*(ll)2 + 1;
	    else if(s%n==0) dis = (s/n)*(ll)2;
	    else {
	    	cout << 0 << "\n";
	    	continue;
	    }
	    // debug(a, dis);
	    for(auto i:a) {
	    	if(i.X == dis-i.X) c += (i.Y*(i.Y-1));
	    	else c += a[dis - i.X] * i.Y; 
	    	// debug(c);
	    }

	    printf("%lld\n", c/(ll)2);
	}
}	