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
	while(t--) {
		scanf("%d", &n);
		vector<vector<int> > g(n+1, vector<int>(n+1));
		for(int i=1; i<=n; i++) {
	  	string s;
	  	cin >> s;
	  	for(int ix=1; ix<=n; ix++) {
	  		g[i][ix] = s[ix-1]-'0';
	  	} 
	  }
	  // debug(g);
	  vector<pp> cooa = {{2,1}, {1,2}};
	  vector<pp> coob = {{n,n-1}, {n-1,n}};
	  vector<int> a = {g[2][1], g[1][2]};
	  vector<int> b = {g[n][n-1], g[n-1][n]};
	  if( a[0] == a[1] && b[0] == b[1] ) {
	  	if(a[0] == b[0]) {
		  	printf("2\n1 2\n2 1\n");
		  } else if(a[0] != b[0]) {
		  	printf("0\n");
		  }
	  } else {
	  	int te = 0;
	  	vector<pp> ans;
	  	if(a[0] != a[1]) {
	  		if(b[0] == b[1]) te = b[0];
				if(a[0] == te) ans.pb(cooa[0]);
				else ans.pb(cooa[1]);
	  	}

	  	te = 1;
	  	if(b[0] != b[1]) {
	  		if(a[0] == a[1]) te = a[0];
				if(b[0] == te) ans.pb(coob[0]);
				else ans.pb(coob[1]);
	  	}

	  	printf("%d\n", ans.size());
	  	while(!ans.empty()) 
	  		printf("%d %d\n", ans.back().X, ans.back().Y), ans.pop_back();
	  }
	}
}