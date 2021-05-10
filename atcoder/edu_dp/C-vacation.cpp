#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n;
	scanf("%d", &n);
	vector<vector<int> > v(n);
	for(int i=0; i<n; i++) {
		for(int ix=0; ix<3; ix++) {
			scanf("%d", &t);
			v[i].push_back(t);
		}
	}
	for(int i=n-2; i>=0; i++) {
		for(int ix=0; ix<3; ix++) {
			v[i][ix] += max(v[i+1][(ix+1)%3],v[i+1][(ix+2)%3]);
		}
	}
	cout << max(v[0][0],max(v[0][1],v[0][2])) << "\n"; 
}