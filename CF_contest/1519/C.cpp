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
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> u(n), s(n);
		map<int, ll> ut;
		map<int, ll> ans;
		map<int, multiset<int, greater<int> > > us;
		map<int, vector<ll> > uc;
		for(int i=0; i<n; i++) {
    	scanf("%d", &u[i]);
    }
		for(int i=0; i<n; i++) {
    	scanf("%d", &s[i]);
    }
    for(int i=0; i<n; i++) {
    	us[u[i]].in(s[i]);
    }
    for(auto u:us) {
    	// sort(u.Y.A(), u.Y.B(), greater<int>());
    	for(auto s:u.Y) {
    		ut[u.X] += s;
    	}
    	uc[u.X].pb(*u.Y.rbegin());
    	for(auto it= ++u.Y.rbegin(); it!=u.Y.rend(); it++) {
    		uc[u.X].pb(uc[u.X].back() + *it);
    	} 
    }

    // debug(us[1]);
    // debug(us[2]);

    // debug(uc[1]);
    // debug(uc[2]);
    for(auto u:us) {
    	int un = u.X;
    	int usz = (int)u.Y.size();
    	for(int i=0; i<usz; i++) {
    		ans[i+1] += ut[u.X] - ( usz%(i+1) ? uc[u.X][usz%(i+1)-1] : 0);
    	} 
    }
    for(int i=1; i<=n; i++) {
    	printf("%lld ", ans[i]);
    	// else printf("0 ");
    }
  	printf("\n");
    // debug(ans);
	}
}