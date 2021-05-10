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
		scanf("%d", &n);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    int c = 0, m = 0;
    for(int i=0; i<n-1; i++) {
    	printf("%d %d\n", m, c);
    	if(c == -1) {
    		if(a[i+1] > a[i]) c = a[i+1]-a[i];
    		else c = a[i+1];
    		m = max(a[i], a[i+1]);
    		continue;
    	}

    	if(a[i+1] > a[i] && a[i+1] != a[i]+c) {
    		p = 0;
    		break;
    	}

    	if(a[i+1] > m ) {
	    	m = a[i+1];
    		continue;
    	}

    	if(a[i+1] < a[i] && a[i+1] > (a[i]+c)%m) {
    		p = 0;
    		break;
    	}

    	if( a[i+1] < (a[i]+c)%m ) {
	    	m += m-a[i]+c - a[i+1];
    	}

    }
    if(p) printf("%d %d\n", m, c);
		else printf("-1\n");
	}
}