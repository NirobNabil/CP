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

#define CEIL(a,b) (a%b ? a/b+1 : a/b)

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
		vector<int> a(n);
		for(int i=0; i<n; i++) {
	    	scanf("%d", &a[i]);
	    }
	    if(n == 2) {
	    	printf("0\n"); continue;
	    } 
	    ll mx = *max_element(a.A(), a.B());
	    ll x = 0;
	    for(int i=0; i<n; i++) {
	    	x += mx - a[i];
	    }
	    debug(x);
	    if(x<mx) {
	    	int g = 0;
	    	g = CEIL((mx-x),(n-1));
	    	x += n*g;
	    	mx += g;
	    	printf("%lld\n", x-mx);
	    }else 
	    	printf("%lld\n", x-mx);
	}
}