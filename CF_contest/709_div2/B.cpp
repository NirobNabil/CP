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
	int i, ix, t, n, a[S1], m, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		if(n < 3) {
			printf("0\n");
			continue;
		}
		for(i=2; a[i-1] - a[i-2] == a[i] - a[i-1] && i<n; i++) {
			continue;
		}
		if(i==2) {
			for(; i<n; i++) {
				if(a[i-2]-a[i-1] == a[i-1]-a[i]) continue;
				else break;
			} 
			if(i == n) {
				i--;
				printf("%d\n", 2*a[i]+a[i-1]-a[i+1]);
				continue;
			}
		}
		// cerr << i << endl;
		if(i==n) {
			printf("0\n");
			continue;
		}else if(i==n-1) {
			printf("-1\n");
			continue;
		}
		c = a[i-1] - a[i-2];
		m = a[i-1] + c - a[i];
		for(; i<n-1 && (a[i]+c)%m == a[i+1]; i++) continue;
		// cerr << m << " " << c << " " << i << endl;
		if(i==n-1) printf("%d %d\n", m, c);
		else printf("-1\n");
	}
}

