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
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		int r[3], c=0;
		memset(r,0,sizeof(r));
		for(int i=0; i<n; i++) r[a[i]%3]++;
		for(int i=0; i<3; i++) {
			for(int x=1, ix=(i+1)%3; ix!=i; x++, ix=(ix+1)%3) {
				if(r[ix]<n/3 && r[i]>n/3) {
					int trix = min(r[i]-n/3, n/3-r[ix]);
					c += trix*x; r[i] -= trix;
					r[ix] += trix;
				}
			} 
		} 
		printf("%d\n", c);
	}
}