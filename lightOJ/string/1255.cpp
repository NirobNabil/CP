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


vector<int> kmp(string &p){
	vector<int> b(p.size()+1);
	// debug(b.size());
	int i = 0, j = -1;
	b[0] = -1;
	while(i < p.size()) {
		while(j >= 0 && p[i] != p[j]) j = b[j];
		i++; j++;
		b[i] = j;
		// debug(i, j, b);
	}
	return b;
}

int main(){
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	int i, ix, t, n, m, k, gg, x, y, z;
	cin >> t;
	for(int it=1; it<=t; it++) {
		string s, p;
		cin >> s >> p;
		auto b = kmp(p);
		int ans = 0;
		debug(b);
		for(int i=0, j=0; i<s.size();) {
			while(j>=0 && p[j] != s[i]) j = b[j];
			i++; j++;
			debug(i, j);
			if(j == p.size()) ans++, j = b[j]; 
		} 
		cout << "Case " << it << ": " << ans << "\n";
	}
}