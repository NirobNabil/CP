#include <bits/stdc++.h>
using namespace std;
#define ll long long int


const ll mod = 10007;
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
			Matrix res(r,B.c);
			// just trust that it works
			for(ll i=0; i<r; i++) 
				for(ll j=0; j<c; j++) 
					for(ll k=0; k<B.c; k++) {
						res.mat[i][k] = ( res.mat[i][k] + mat[i][j] * B.mat[j][k] ) % mod;
					}
			return res;
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
			res = A * res;
		e /= 2;
		A = A * A ;
	}
	return res;
}


int main(){
	int tc, a, b, c, i, ix, t, n, m, k, p, q, gg, x, y, z;
	cin >> t;
	for(tc=1; tc<=t; tc++) {
		cin >> n >> a >> b >> c;
		Matrix A(4,4);
		Matrix B(4,1);
		A.mat = {
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ b, 0, a, c },
			{ 0, 0, 0, 1 }
		};
		B.mat = {
			{0},
			{0},
			{0},
			{1}
		};
		A = exp(A,n);
		B = A * B;
	    cout << "Case " << tc << ": " << B.mat[0][0] << "\n";
	}
}