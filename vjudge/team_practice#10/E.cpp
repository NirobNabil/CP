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
	int i, ix, t, n, b;
	std::vector<int> a(S1);
	scanf("%d %d", &n, &b);
	rep(i, 0, n) scanf("%d", &a[i]);

	int m = 0;
	for(int i=1; i<n; i++) {
		if(a[i] < a[m]) m = i;
	}

	// printf("%d\n", m);

	vector<int> temp;
	for(int i=0; i<=n; i++) {
		temp.pb(a[m]);
		m = (m + 1) % n;
	} 

	a = temp;

	// for(auto i:a) printf("%d ", i);
	// printf("\n");

	deque<int> q;
	vector<int> ans(n+9);
	for(int i=0; i<=n; i++)  {
		while(i+1<=n && a[i]<a[i+1]) {
			q.push_back(i);
			i++;
		}
		q.push_back(i);
		int c = a[ q[0] ]==0?0:1;

		// for(auto i:q) printf("%d ", i);
		// printf("\n");

		while(q.size()) {
			ans[ q[0] ] = max(ans[ q[0] ], q.size()>1 && a[ q[0] ]==a[ q[1] ]?c:c++); 
			q.pop_front();
		}

		if(i > n) break;

		while(i+1<=n && a[i]>a[i+1]) {
			q.push_back(i);
			i++;
		}
		q.push_back(i);
		c = ( int ) q.size() - (a [ q.back() ]==0?1:0);

		// for(auto i:q) printf("%d ", i);
		// printf("\n");

		// cerr << "gg" << endl;
		while(q.size()) {
			ans[ q[0] ] = max(ans[ q[0] ], q.size()>1 && a[ q[0] ]==a[ q[1] ]?c:c--); 
			q.pop_front();
		}

		q.push_back(i);

		if(i > n) break;

	}



	// for(int i=0; i<n; i++)  {
	// 	printf("%d ", ans[i]);
	// }
	// printf("\n");
	// printf("%d\n", m);
	m = (n - m + 1)%n;

	for(int i=0; i<n; i++)  {
		printf("%d ", ans[m]);
		m = (m+1)%n;
	}
}