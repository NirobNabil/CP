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

#define graph map<int, map<int,int> >

map<int, map<int,pair<int,int> > > dp; 
graph g;

void bfs() {
	queue<tuple<int,int,int,int> > q;
	int n, w, l, p;
	q.push(mt(1, 0, 1, 0));
	while(!q.empty()) {
		tie(n,w,l,p) = q.front();
		for(auto i:g[n]) {
			q.push(mt(i.X, w+i.Y, l+1, n));
		}

		if(dp[n].find(l) != dp[n].B() && dp[n][l].X > w) {
			dp[n][l] = {w, p};
		} else dp[n][l] = {w, p};
		q.pop();
	}
}

stack<int> ans;
void backtrack(int n, int l) {
	if(l == 0) return;
	ans.push(n);
	backtrack(dp[n][l].Y, l-1);
}

int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> a(n);
	for(int i=0; i<m; i++) {
  	scanf("%d %d %d", &x, &y, &z);
  	g[x][y] = z;

  }
  bfs();
  // for(int i=1; i<=n; i++) {
	 //  debug(i, dp[i]);
  // } 
 //  if(k==200) {
 //  	for(auto i:dp[n]) {
	//   	printf("%d %d %d\n", i.X, i.Y.X, i.Y.Y);
	//   }
	// }
	// debug(dp[n]);
  for(auto it=dp[n].rbegin(); it != dp[n].rend(); it++) {
  	if(it->Y.X > k) continue;
  	printf("%d\n", it->X);
	  backtrack(n, it->X);
	  while(!ans.empty()) 
	  	printf("%d ", ans.top()), ans.pop();
	  printf("\n");
  	break;
  }
  // cout << dp[n].rbegin()->Y << endl;
}