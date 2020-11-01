#include "bits/stdc++.h"
using namespace std;
#define ll long long int


int main(){
	int t;
	scanf("%d", &t);
	std::vector<ll> v;
	v.push_back(0);
	ll x, y=10;
	for(ll i=2; i<y; i++) {
		x=(i%2==1?i/2+1:i/2);
		v.push_back( (y/i)*2 - 2*x + x ); 
	}
	for(auto i:v) cout << i << endl;
	// while(t--){
	// 	int n;
	// 	scanf("%d", &n);

	// }
}