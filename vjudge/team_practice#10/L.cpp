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
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	int i, ix, t, n, a[S1];
	cin >> n;
	vector<string> v;
	string s;
	
	for(int i=0; i<n; i++) {
		cin >> s;
		v.pb(s);
	}

	vector<string> vs(n);
	vector<int> vb(n, 1);
	for(int i=0; i<n; i++) {
		vs[i] = v[i] + v[i];
	}

	// for(auto i:vs) cout << i << endl;
	for(int i=0; i<n; i++) {
		if(vb[i] == 0) continue;
		for(int ix=i+1; ix<n; ix++) {
			// printf("%d %d\n", i, ix);
			// for(auto i:vb) printf("%d ", i);
			// printf("\n");
			if(vs[ix].size() != v[i].size() * 2) continue;
			if(vb[ix] == 0) continue;
			if(vs[ix].find( v[i] ) != -1) vb[ix] = 0;
			else continue; 
		}
	}

	int c = 0;
	for(int i=0; i<n; i++) if(vb[i] == 1) c++;

	cout << c << "\n";
}