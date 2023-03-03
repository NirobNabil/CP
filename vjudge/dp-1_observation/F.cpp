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


const int N = 150;
int dp[N][N];
string s;


int chk(int i, int j) {
	if(dp[i][j]) return dp[i][j];
	if(i >= j) return 0;

	if( s[i] == s[j] ) return dp[i][j] = chk(i+1, j-1);
	else return dp[i][j] = min( chk(i+1, j), chk(i, j-1) ) + 1;
} 


int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	cin >> t;
	for(int it=1; it<=t; it++) {
		for(int i=0; i<N; i++)
			for(int ix=0; ix<N; ix++) 
				dp[i][ix] = 0; 
		cin >> s;
		cout << "Case " << it << ": " << chk(0, s.length()-1) << "\n";
	}
}