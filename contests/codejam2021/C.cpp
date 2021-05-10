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

int i, ix, t, n, k;

int mini(vector<int> &a, int i) {
	int mi=i;
	while(++i<n) {
		if(a[mi] > a[i]) mi = i; 
	}
	return mi;
}


int main(){
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++) {
		printf("Case #%d: ", tc);
		int pos = 0;
		vector<int> a;
		scanf("%d %d", &n, &k);
		for(int i=1; i<=n; i++) a.pb(i);

		do {
			vector<int> ta = a;
			int c = 0, tmp=0;
			for(int i=0; i<n-1; i++) {
				tmp = mini(ta, i);
				c += tmp - i + 1;
				reverse(ta.A()+i, ta.A()+tmp+1);
			}
			if(c == k) {
				pos = 1;
				break;
			}
		} while(next_permutation(a.A(), a.B()));

		if(pos) {
			for(auto i:a) printf("%d ", i);
			printf("\n");
		}else printf("IMPOSSIBLE\n");
	}
}