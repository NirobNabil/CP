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

//  WWTLL
// L WWTL
// LL WWT
// TLL WW
// WTLL W
// WWTLL 

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n--;
		if(n==1) {
			printf("0\n");
			continue;
		}
		vector<int> s;
		if(n%2==1) {
			for(int i=0; i<n/2; i++) s.push_back(1);
			s.push_back(0);
			for(int i=0; i<n/2; i++) s.push_back(-1);
		}else {
			for(int i=0; i<n/2; i++) s.push_back(1);
			for(int i=0; i<n/2; i++) s.push_back(-1);	
		}
		// for(auto i:s) printf("%d ", i);
		printf("\n");
		for(int i=0, ix=n; i<n; i++, ix--) {
			for(int xx=0; xx<ix; xx++) printf("%d ", s[xx]);
			printf(" ");
			// printf("\n");
			// for(; i<n; i++) printf("%d ", s[i]);
		} 
	}
}