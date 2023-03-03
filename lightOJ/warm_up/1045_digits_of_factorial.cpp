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
	int i, ix, t, tc=0, n, m;
	scanf("%d", &t);
	vector< double > v(10e5+13, 0);
	for(int i=1; i<=10e5+9; i++) {
		double temp = 0;
		for(int ix=1; ix<=10; ix++) {
			temp += log2((i-1)*10+ix);
		} 
		v[i] = v[i-1] + temp;
	}
	while(++tc <= t){
		scanf("%d %d", &n, &m);
		double ans = v[n/10];
		for(int i=(n/10)*10+1; i<=n; i++) ans += log2(i);
		printf("Case %d: %.0lf\n", tc, n==0?1:ceil(ans/log2(m)));
	}
}