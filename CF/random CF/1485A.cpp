#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n, nb, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		ll pn=LONG_MAX, ta=a, tb=b, nb=0;
		if(b==1) b++, nb=1;
		while(1) {
			n=0;  ta=a;
			while(ta>0) {
				ta = ta/b;
				n++;
			}
			// fprintf(stderr, "%lld %lld %lld\n", n,nb,pn);
			if(n+nb<=pn) {
				pn = n+nb;
				b++;  nb++;
				continue;
			}
			printf("%d\n", pn);
			break;
		} 
	}
}