#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000



int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    for(int i=0; i<n-1 && k>0; i++) {
    	int tm = min(a[i], k);
    	a[i] -= tm;
    	a[n-1] += tm;
    	k -= tm;
    }
    for(auto i:a) printf("%d ", i);
    printf("\n");
	}
}