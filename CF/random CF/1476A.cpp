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
#define CEIL(a,b) (a%b?a/b+1:a/b)

int main(){
	int i, ix, t, n, k, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		k = CEIL(n,k)*k;
		printf("%d\n", CEIL(k,n));
	}
}