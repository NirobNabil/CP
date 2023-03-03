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

typedef vector<int> vi;

vi generate_lps( string p ) {
	vi lps( p.length() );
	int i=0, j=-1, n = p.length();
	lps[0] = -1;
	while( i < n ) {
		while( j>=0 && p[i]!=p[j] )
			j = lps[j];
		i++; j++;
		lps[i] = j;
	}
	return lps;
}

// returns the indexes where match occured
vi kmp( string s, string p ) {
	vi matches;
	vi lps = generate_lps(p);
	int i=0, j=-1, n = s.length(), m = p.length();
	lps[0] = -1;
	while( i < n ) {
		while( j>=0 && s[i]!=p[j] )
			j = lps[j];
		i++; j++;
		if( j == m ) 
			matches.push_back( i-m );
	}
	return matches;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, k, p, q, gg, x, y, z, pos;
	t = 1;
	while(t--){
		string s, p;
		cin >> s >> p;
		vi matches = kmp( s, p );
		for( auto i : matches ) {
			cout << i << " ";
		}
		cout << "\n";
	}
}