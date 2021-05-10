#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int op1(multiset<int> &a) {
	int x = *(--a.end());
	a.erase((--a.end()));
	int ans = *(--a.end()) - *a.begin();
	a.insert(x);
	return ans;
}

int op2(multiset<int> &a) {
	int x = *(a.begin());
	a.erase(a.begin());
	int ans = *(--a.end()) - *a.begin();
	a.insert(x);
	return ans;
}

int main(){
	int i, ix, t, n, x, y, z;
	scanf("%d", &n);
	multiset<int> a;
	for(int i=0; i<n; i++) {
    scanf("%d", &x);
    a.insert(x);
  }

  ll ans = 0;
  while(a.size() > 1) {
  	int x = op1(a);
  	int y = op2(a);

  	// printf("%d %d %d -", x, y, *a.rbegin() - *a.begin());
  	// for(auto i:a) printf("%d ", i);
  	// printf("\n");
  	if(x < y) {
  		ans += *a.rbegin() - *a.begin();
  		a.erase((--a.end()));
  	}else if(y < x){
  		ans += *a.rbegin() - *a.begin();
  		a.erase(a.begin());
  	}else {
  		if(a.count(*a.rbegin()) < a.count( *a.begin() )) {
  			ans += *a.rbegin() - *a.begin();
  			a.erase((--a.end()));
  		}else {
  			ans += *a.rbegin() - *a.begin();
  			a.erase(a.begin());
  		}
  	}

  }

  printf("%lld\n", ans);
}