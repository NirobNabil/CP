#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int main(){
	int i, ix, t, n, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
      scanf("%d", &a[i]);
    }
    vector<int> e, o;
    for(int i=0; i<n; i++) {
    	if(a[i] % 2 == 0) e.pb(a[i]);
    	else o.pb(a[i]);
    }
    for(auto i:e) printf("%d ", i);
    for(auto i:o) printf("%d ", i);
    printf("\n");
	}
}