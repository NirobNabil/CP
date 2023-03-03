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



const ll mod = 42949672961578;
typedef vector<vector<ll> > matrix ; 

class Matrix {
	public:
		matrix mat;
		ll r, c;
		Matrix(ll r, ll c) {
			this->r = r;
			this->c = c;
			mat.resize(r, vector<ll>(c) );			
		}

		vector<ll> operator [] (ll i) const { return mat[i]; }
		vector<ll>& operator [] (ll i) { return mat[i]; }

		Matrix operator *( Matrix const &B ) {
			Matrix res(r,c);
			// just trust it this works
			for(ll i=0; i<r; i++) 
				for(ll j=0; j<c; j++) 
					for(ll k=0; k<B.c; k++) {
						res.mat[i][k] = ( res.mat[i][k] + mat[i][j] * B.mat[j][k] ) % mod;
					}
			return res;
		}

		Matrix operator %( ll mod ) {
			Matrix t = *this;
			for(auto row : mat) 
				for(ll i=0; i<row.size(); i++)
					row[i] %= mod;
			return t;
		}

		void print() {
			for(auto row:mat) {
				for(auto col:row) cout << col << " ";
				cout << "\n";
			}
		}

		void initialize_unit() {
			for(int i=0; i<r; i++) {
				mat[i][i] = 1;
			} 
		}

};


Matrix exp( Matrix A, ll e ) {
	Matrix res(A.r,A.c);
	res.initialize_unit();
	while(e) {
		if( e % 2 ) 
			res = res * A;
		e /= 2;
		A = A * A ;
	}
	return res;
}


Matrix grid(64, 64);

void gen(int p, int r, int c) {
	debug(r,c);
	if(r > 7 || c > 7 || r < 0 || c < 0) return;
	int cur = r*8 + c;
	if(grid.mat[p][cur]) return;
	// grid.mat[cur][cur] = 1;
	grid.mat[p][cur] = 1;
	gen(cur, r+1, c-2);
	gen(cur, r+1, c+2);
	gen(cur, r-1, c-2);
	gen(cur, r-1, c+2);
	gen(cur, r+2, c-1);
	gen(cur, r+2, c+1);
	gen(cur, r-2, c-1);
	gen(cur, r-2, c+1);
}

int main(){
	ll i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%lld", &n);
	gen(0, 0, 0);
	grid = exp(grid, n);
	// grid.print();
	ll ans = 0;
	for(int i=0; i<64; i++) {
		ans = ( ans + grid[0][i]) % mod;
	}
	cout << ans << "\n";
}