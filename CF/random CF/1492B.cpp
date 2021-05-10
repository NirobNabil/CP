#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

ll tcost=0, lcost=0;
ll i, ix, t, n, a[S1], b[S1], d[S1];
bool c[S1];

ll dp(int x) {
	if(x<=0) return 0;
	if(b[x]) return b[x];
	ll dpv = dp(x-1);
	if(a[x]+dpv+d[x-1] > a[x]*x+dpv) {
		b[i] = a[x]+dpv+d[x-1];
		c[i] = 1;
	}else {
		b[i] = a[x]*x+dpv;
		c[i] = 0;	
	}
	return b[i];
}

void print_f(int x) {
	if(x==0) return;
	if(!c[x]) {
		printf("%lld ", a[x]);
		print_f(x-1);
	}else {
		print_f(x-1);
		printf("%lld ", a[x]);
	}
}

int main(){
	scanf("%ld", &t);
	while(t--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(b, 0, sizeof(d));
		scanf("%lld", &n);
		rep(i, 1, n+1) scanf("%lld", &a[i]);
		for(int i=1; i<=n; i++) tcost += (n-i+1)*a[i];
		for(int i=1; i<=n; i++) d[i] += a[i]+d[i-1];
		ll mval = 0, m_i=0; 
		for(int i=0; i<n; i++) {
			ll dpv = dp(i);
			cerr << "gg" << endl;
			printf("%d %lld %lld %lld\n", i, dpv, tcost, mval);
			if(tcost + dpv > mval) {
				mval = tcost + dpv;
				m_i = i;
			}
			tcost = tcost + (d[n]-d[i+1]) - a[i+1]*n;
		}
		printf("%lld \n", m_i);
		printf("C- \n");
		for(int i=1; i<=n; i++) printf("%d ", c[i]);
		printf("\n");
		for(int i=m_i+1; i<=n; i++) printf("%lld ", a[i]);
		print_f(m_i);
	}
}