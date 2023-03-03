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

double calc(double x, double y) {
	return sqrt(x*x + y*y);
}

int main(){
	int i, ix, t, n;
	long double x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		std::vector<long double> v1, v2;
		for(int i=0; i<n*2; i++) {
			scanf("%Lf %Lfs", &x, &y);
			if(x==0) v2.pb(abs(y));
			else if(y==0) v1.pb(abs(x));
		}
		sort(v1.A(), v1.B());
		sort(v2.A(), v2.B());
		long double ans = 0;
		for(int i=0; i<n; i++) {
			ans += calc(v1[i], v2[i]);
		}
		printf("%.15Lf\n", ans); 
	}
}