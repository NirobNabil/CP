#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll mod = 1000000007;
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



int main() {
	Matrix A(2,2);
	Matrix B(1,2);
	A.mat = { {0,1}, {1,1} };
	B.mat = { {0,1} };
	A = exp(A, 2);
	// A.print();
	B = B * A;
	B.print();
	
}