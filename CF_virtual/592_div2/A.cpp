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
		int a,b,c,d,k,done=0;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		for(int i=0; i<=k; i++) {
			if(i*c>=a && (k-i)*d>=b) {
				printf("%d %d\n", i, k-i);
				done=1;
				break;
			}
		} 
		if(!done) printf("-1\n");
	}
}