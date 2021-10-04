#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<int> a(S1, 0);
int i, ix, t, n;

int mini(int i) {
	int mi=i;
	while(++i<n) {
		if(a[mi] > a[i]) mi = i; 
	}
	return mi;
}

int main(){
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++) {
		fill(a.A(), a.B(), 0);
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		int c = 0, tmp=0;
		for(int i=0; i<n-1; i++) {
			tmp = mini(i);
			c += tmp - i + 1;
			reverse(a.A()+i, a.A()+tmp+1);
		}
		printf("Case #%d: %d\n", tc, c);
	}
}