#include <bits/stdc++.h>
using namespace std;
#define ll long long long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 400000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	long long int i, ix, t, n, nn, k[S1], c[S1];
	cin >> t;
	while(t--){
		cin >> n >> nn;
		rep(i, 0, n) scanf("%lld", &k[i]);
		rep(i, 0, nn) scanf("%lld", &c[i]);
		map<long long int,vector<long long int> > a;
		for(long long int i=0; i<n; i++) {
			a[c[k[i]-1]].push_back(k[i]-1);
		}  
		long long int ans=0, min_i=0, mini=0;
		for(auto i=a.rbegin(); i!=a.rend(); i++) {
			for(auto ix:(*i).Y) {
				mini = (ix>=min_i && min_i<nn)?c[min_i]:c[ix];
				// cout << (*i).X << " " << ix << " " << mini << "\n";
				if(mini<c[ix]) {
					ans += mini;
					min_i++;
				}else ans += c[ix];
			}
		}
		printf("%lld\n", ans);
	}
}