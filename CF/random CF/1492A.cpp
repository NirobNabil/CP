#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll i, ix, t, n, p, a, b, c;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld %lld", &p, &a, &b, &c);
		printf("%lld\n", min(a-p%a==a?0:a-p%a, min(b-p%b==b?0:b-p%b, c-p%c==c?0:c-p%c)));
	}
}