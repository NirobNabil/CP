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

map<int,int> dp[3009];
vector<int> a(3009);
int n;

ll chk(int i, ll h) {
	// auto it = dp[i].upper_bound(h);
	// debug(i,h);
	// if(it != dp[i].begin() && dp[i].size() > 0) {
	// 	--it;
	// 	return it->Y;	
	// }
	if(dp[i][h]) return dp[i][h];
	if(h < 0) return INT_MIN;
	if(i >= n) return 0;
	if(a[i] >= 0) dp[i][h] = chk(i+1, h+a[i])+1;
	else dp[i][h] = max(chk(i+1, h+a[i])+1,chk(i+1, h));
	// debug(i,h,dp[i][h]);
	return dp[i][h];
}

int main(){
	int i, ix, t, m, k, p, q, gg, x, y, z;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    cout << chk(0, 0) << "\n";
    // for(int i=0; i<n; i++) {
    // 	for(auto x:dp[i]) {
    // 		printf("%d - %d - %d\n", i, x.X, x.Y);
    // 	}
    // 	printf("\n");
    // }
    // debug(dp);
}