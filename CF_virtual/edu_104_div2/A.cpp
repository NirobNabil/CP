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
		sort(a, a+n);
		bool xd=true;
		for(int i=0; i<n && xd; i++) {
			if(i==n-1) {
				a[i]=-1;
				continue;
			}
			if(a[i+1]!=a[i]) xd=false;
			a[i]=-1;
		} 
		int cnt=0;
		for(int i=n-1; i>=0 && a[i]!=-1; i--) cnt++;
		printf("%d\n", cnt); 
	}
}