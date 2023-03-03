#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n;
	vector<pair<ll,int> > a, b(S1);
	scanf("%d", &t);
	while(t--){
		a.clear();
		b.clear();
		scanf("%d", &n);
		rep(i, 0, n) {
			scanf("%d", &ix);
			a.push_back({ix,i+1});
		}
		if(n==1) {
			printf("1\n1\n");
			continue;
		}
		sort(a.begin(), a.end());
		b[0] = a[0];
		for(int i=1; i<n; i++) {
			b[i].X = b[i-1].X + a[i].X;
			b[i].Y = a[i].Y;
		}
		int c = -1;
		for(int i=0; i<n-1; i++) {
			if(b[i].X<a[i+1].X) c=i; 
		}
		printf("%d\n", n-c-1);
		std::vector<int> v;
		for(int i=c+1; i<n; i++) v.pb(b[i].Y);
		sort(v.A(), v.B());
		for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
		printf("\n");
	}
}