#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long int
#define X first
#define Y second
#define MOD 998244353

int main(){
	int n;
	scanf("%d", &n);
	char a[100000][12];
	for(int i=0; i<n; i++) scanf("%s", &a[i]);
	int l = strlen(a[0]);
	ll ans = 0, g, x, r=0, k;
	for(int i=l-1; i>=0; i--) {
		k=0, x=0;
		for(int ix=0; ix<n; ix++) {
			k += ((a[ix][i]-'0')*n) %MOD;
			k %= MOD;
		}
		g = (k+r)%MOD;
		r = (g-g%10)/10;
		x = g%10;
		ans += ( (x%MOD) * (ll)pow(10,(l-i-1))%MOD * (ll)pow(10,(l-i-1))%MOD )%MOD;
		g = (k + r)%MOD;
		r = (g-g%10)/10;
		x = g%10;
		ans += ( (x%MOD) * (ll)pow(10,(l-i-1))%MOD * (ll)pow(10,(l-i-1)+1)%MOD )%MOD;
		ans %= MOD;	
	}  	
	if(r>0) ans += ( (r%MOD) * (ll)pow(10,l )%MOD * (ll)pow(10,l )%MOD )%MOD;
	ans %= MOD;
	printf("%lld\n", ans);
}