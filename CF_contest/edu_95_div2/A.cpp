#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define CEIL(a,b) ((b*(a/b) < a) ? a/b+1 : a/b)

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll x,y,k;
		cin >> x >> y >> k;
		cout << 1 + CEIL((k*y + k - x),(x-1)) + k << endl;
	}
}