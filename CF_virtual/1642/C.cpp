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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, pos;
	cin >> t;
	while(t--){
		cin >> n >> x;

		map<ll,int> ignore;
		map<ll, vector<ll> > a;
		vector<ll> b;
		for(int i=0; i<n; i++) {
	    	cin >> z;
	    	b.pb(z);
	    }
	    sort(b.A(), b.B());

	    for(int i=0; i<n; i++) 
	    	a[b[i]].push_back(i);

	    for(auto i:a) 
	    	sort(i.Y.A(), i.Y.B(), greater<int>());

	    int count = 0;
	    for(int i=0; i<n; i++) {
	    	if(ignore[i]) continue;
	    	debug(b[i], b[i]*x);
	    	if( a[b[i]*x].size() > 0 ) {
	    		ignore[a[b[i]*x].back()] = 1;
	    		a[b[i]*x].pop_back();
	    	}else count++;
	    }

    	cout << count << "\n";
	}
}