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
	int t, n, m, k, p, q, pos, x, y, z;
	cin >> t;
	while(t--){
		cin >> n;
		pos = 1;
		map<int, map<int, int> > tree;
		vector<int> ans(n-1);
		int g[] = {2,3}; 
		for(int i=0; i<n-1; i++) {
			cin >> x >> y;
			tree[x][y] = i;
			tree[y][x] = i;
		}

		auto assign = [&]( int p, int c, bool x, auto&& assign) {
			ans[tree[p][c]] = g[x];
			if( tree[c].size() == 1 ) return;
			if( tree[c].size() > 2 ) pos = false;
			for( auto i:tree[c] ) {
				if( i.X == p ) continue;
				else assign( c, i.X, !x, assign );
			}
		};

		int start = 1;
		for(auto i:tree) {
			if( i.Y.size() == 1 ) start = i.X;
		}
		assign(start, tree[start].begin()->X, g[0], assign);

		if( pos == 0 ) {
			cout << "-1\n";
		}else {
			for( auto i:ans ) cout << i << " ";
			cout << "\n";
		}
	}
}