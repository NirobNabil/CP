#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<ll,ll>

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


int i, ix, t, n, m, k, p, x, y, z;
vector<int> v;\
vector<pp> c;
string s, gg;

int coo(int x, int y) {
	if(x>=m || x<0 || y>=m || y<0) return -1;
	return y*n + x;
}

pp dfs(int node, int d);

void chk(int pnode, int i, int j, int pd, int d) {
	int x = pnode%n;
	int y = pnode/m;
	int node = coo(x+i, y+j);
	// debug(node);
	pp ret = dfs(node, d);
	if(d != pd) {
		c[pnode] = make_pair( min(c[pnode].X, ret.X + 1), ret.Y );
	}else c[pnode] = make_pair( min(c[pnode].X, ret.X), ret.Y );
}


pp dfs(int node, int d) {
	if( node >= n*m || node < 0 || s[node] == 'X' ) return {INT_MAX, d};
	if(c[node].X != INT_MAX) return c[node];
	if(s[node] == 'F') return make_pair(1, d);
	debug("p", node);
	v[node] = 1;
	chk(node, 0, 1, d, 1);
	chk(node, 1, 1, d, 2);
	chk(node, 1, 0, d, 3);
	chk(node, 1, -1, d, 4);
	chk(node, -1, 0, d, 5);
	chk(node, -1, -1, d, 6);
	chk(node, -1, 0, d, 7);
	chk(node, -1, 1, d, 8);
	debug(node, c[node]);
	return c[node];
}


pp bfs(int node, int d) {
	if( node >= n*m || node < 0 || s[node] == 'X' ) return {INT_MAX, d};
	if(c[node].X != INT_MAX) return c[node];
	if(s[node] == 'F') return make_pair(1, d);
	debug("p", node);
	while(!q.empty()) {
		node = q.pop()
		v[node] = 1;
		chk(node, 0, 1, d, 1);
		chk(node, 1, 1, d, 2);
		chk(node, 1, 0, d, 3);
		chk(node, 1, -1, d, 4);
		chk(node, -1, 0, d, 5);
		chk(node, -1, -1, d, 6);
		chk(node, -1, 0, d, 7);
		chk(node, -1, 1, d, 8);	
	}
	
	debug(node, c[node]);
	return c[node];
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		s = "";
		for(int i=0; i<n; i++) {
			cin >> gg;
			s += gg;
	    }
	    v.resize(n*m+9);
	    c.resize(n*m+9);
	    fill(c.A(), c.B(), make_pair(INT_MAX, -1));
	    int source, dest;
	    for(int i=0; i<s.length(); i++) {
	    	if(s[i]=='S') source = i;
	    	if(s[i]=='F') dest = i;
	    } 
	    int ans = dfs(source, -1).X;
	    debug(ans);
	    if(ans >= INT_MAX) cout << -1 << "\n";
	    else cout << ans << "\n";
	}
}