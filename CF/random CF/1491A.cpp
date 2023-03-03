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
	int i, ix, t, tp, k, x, n;
	scanf("%d %d", &n, &k);
	std::vector<int> v;
	std::deque<int> q;
	rep(i, 0, n) scanf("%d", &x), v.pb(x);
	for(auto i:v) q.pb(i);
	sort(q.begin(), q.end(), greater<int>());
	for(int i=0; i<k; i++) {
		scanf("%d %d", &tp, &x);
		if(tp==1) {
			if(v[x-1]==0) {
				q.pop_back();
				q.push_front(1); 
				v[x-1]=1;
			} else {
				q.pop_front();
				q.push_back(0); 
				v[x-1]=0;
			}
		}else printf("%d\n", *(q.A()+x-1));
		// for(auto i:q) printf("%d - ", i);
		// printf("\n");
		// for(auto i:v) printf("%d - ", i);
		// printf("\n\n");
	}	
}