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
	int i, ix, t, n, u, v, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &u, &v);
		rep(i, 0, n) scanf("%d", &a[i]);
		int cost = INT_MAX;
		for(int i=0; i<n-1; i++) {
			if(a[i]==a[i+1]) cost = min(cost, min(u+v, v+v));
			else if(a[i]+1==a[i+1] || a[i]-1==a[i+1]) 
				cost = min(cost, min(u,v));
			else cost = min(0, cost);
		}
		printf("%d\n", cost);
	}
}