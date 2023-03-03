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


vector<int> a;
int state = 1;

int p( int n ) { return n / 2; }
int c1( int n ){ return n*2; }
int c2( int n ){ return n*2+1; }
int f( int n ) {
	int i = upper_bound(a.A(), a.B(), n) - a.A();
	// debug(n, (i%2) ^ state);
	return (i%2) ^ state;
}

int trav( int s, int d ) {
	int ans = 0;
	vector<int> t1;
	while( s >= 1 ) t1.pb(s), s = p(s);
	while( d >= 1 ) {
		auto it = find( t1.A(), t1.B(), d );
		if( it != t1.B() ) {
			int i = it - t1.A();
			while( i>=0 ) {
				ans += f( t1[i--] );
			}
			return ans;
		} else ans += f(d);
		d = p(d);
	}
	return -1;
}


int main(){
	for(int i=0; i<32; i++) a.pb( 1<<i );
	// debug(a);
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		if( s == "Qi" ) state = !state;
		else if( s == "Qb" ) {
			state = !state;
			cin >> x >> y;
			cout << trav( x, y ) << "\n";
			state = !state;
		}else {
			cin >> x >> y;
			cout << trav( x, y ) << "\n";
		}
	}

}