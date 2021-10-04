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
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		int gg, c=0;
		for(int i=0; i<n-1; i++) {
			if((double)max(a[i+1],a[i])/(double)min(a[i+1],a[i]) <= 2.0) continue;
			if(a[i]<a[i+1]) {
				while(a[i]<<1 <a[i+1]) a[i]=a[i]<<1, c++;
			}else {
				while(CEIL(a[i],2) >a[i+1]) a[i]=CEIL(a[i],2), c++;
			}
		}
		printf("%d\n", c);
	}
}