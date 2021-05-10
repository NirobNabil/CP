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

auto below(vector<int>::iterator begin, vector<int>::iterator end, int i) {
	auto it = lower_bound(begin, end, i);
	if(it==begin) return end;
	if(*it==i) return it;
	return --it;
}

int main(){
	int i, ix, t, n, m, x, y;
	map<int,int> a, b, as;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		vector<int> av, bv, bc1(m+9);
		vector<pair<int,int> > bc2(m+9);
		rep(i, 0, n) scanf("%d", &x), av.push_back(x);
		rep(i, 0, m) scanf("%d", &x), bv.push_back(x);
		a[av[0]] = 1;
		for(int i=1; i<n; i++)  {
			a[av[i]] = a[av[i-1]]+1;
		}
		for(int i=0; i<m; i++) {
			auto it = below(av.A(), av.B(), bv[i]);
			printf("s %d\n", *it);
			if(it==av.B()) bc1[i] = 0;
			else bc1[i] = a[*it];
		}

		for(int i=m-1; i>=0; i--) {
			bc2[i] = { bv[i], bc2[i+1].Y + binary_search(av.A(), av.B(), bv[i]) };
		}

		// int mx = 0;
		// for(int i=0; i<m; i++) {
		// 	bc1[i] + 
		// }

		for(auto i:a) cout << i.X << "|" << i.Y << endl;
		cout << endl;
		for(int i=0; i<m; i++) cout << i << "-" << bc1[i]  << endl;
		cout << "gg" << endl;
		for(int i=0; i<m; i++) printf("%d %d\n", bc2[i].X, bc2[i].Y);
		cout << endl;	
		
	}
}