#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		int n, m;
		scanf("%d %d", &n, &m);
		ll ans = 0;
		ans += (int)(abs(m-n))*4 + n*4;
		ans += 5*2 + 3*3;
	  printf("Case %d: %d\n", ix, ans);
	}
}