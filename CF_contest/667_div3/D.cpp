#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll r=0, s, l, t_i=0;
		char n[20];
		scanf("%s %lld", &n, &s);
		l = strlen(n);
		for(int i=l-1; i>=0; i--) { 
			t_i += n[i] - '0';
		}
		t_i = t_i - s;
		for(ll i=l-1; i>=0 && t_i; i--) {
			r += i * ( min((ll)9,t_i) - (ll)(n[i]-'0') );
			t_i = min((ll)9,t_i) - (ll)(n[i]-'0');
		}
		printf("%lld\n", r);
	}
}