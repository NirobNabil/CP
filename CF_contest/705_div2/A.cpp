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
	int i, ix, t, n, k, a[S1];
	scanf("%d", &t);
	while(t--){
		std::vector<int> v;
		scanf("%d %d", &n, &k);
		for(int i=n; i>=0; i--) {
			if(i>k) {
				v.pb(i);
				continue;
			}
			if(i<k && i+1+i>k) {
				v.pb(i);
				continue;
			}
		} 
		printf("%d\n", v.size());
		for(auto i:v) printf("%d ", i);
		printf("\n");
	}
}