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
#define mp make_pair

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

int chk(int a, int b, int c) {
	if(a==c || a==b) return 0;
	return 1; 
}


int main(){
	int i, ix, t=1, n, m, k, p, q, gg, x, y, z;
	while(t--){
		scanf("%d %d", &n, &x);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    vector<pp> as;
    vector<pair<int, pp> > ps;
    for(int i=0; i<n; i++) {
        as.push_back({a[i], i});
    	for(int ix=0; ix<i; ix++) {
    		ps.push_back({a[i]+a[ix], {i, ix}});
    	}
    }
    sort(as.A(), as.B());
    // debug(ps);
    for(auto i:ps) {
    	auto ait = lower_bound(as.A(), as.B(), mp(x - i.X, 0));
    	for(; ait!=as.B() && ait->X==x-i.X; ait++) {
    		if(chk(ait->Y, i.Y.X, i.Y.Y) ) {
    			printf("%d %d %d\n", ait->Y+1, i.Y.X+1, i.Y.Y+1);
    			return 0;
    		}
	    	// debug(*pit);    	
    	}
    	// debug(*pit);    	
    	// debug("0");
    }
    printf("IMPOSSIBLE\n");
	}
}