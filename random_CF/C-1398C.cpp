#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int a[100005], r=0;
unordered_map<int, vector<int> > b;
unordered_map<int, unordered_map<int, int> > sub;
set<int> c;
int fact[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int ncr(int n, int r){
	return fact[n]/(fact[r]*fact[n-r]);
}

auto lower_bound(int x) {
	auto g = c.lower_bound(x);
	if(g == c.begin()) return g;
	else return --g;
}

int subs(int x, int y){
	if(x==0 || x<y) return 0;
	else if(sub[x][y]) return sub[x][y];
	int gg, iy=c.find(y), iz=1;
	if(y>1) gg = x/(y-1);
	else gg = x;
	for(int xi=x; xi>0; xi-=y, iz++){
		for(auto i=iy; i!=c.begin(); i--){
			// try {
			// 	gg += sub[x-y][*i];
			// } catch(std::out_of_range& e) {
				gg += subs(xi, *i) * ;
			// } 
		}
	}
	sub[x][y] = gg*b[i].size();
	r+=b[i].size();
	return gg;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		r=0;
		sub.clear();
		b.clear();
		c.clear();
		int n;
		scanf("%d", &n);
		char x[n];
		scanf("%s", x);
		for(int i=0; i<n; i++) a[i] = x[i] - '0', c.insert(a[i]);
		c.erase(0);
		c.erase(1);
		for(int i=0; i<n; i++) {
			b[a[i]].push_back(i);
		}
		// cout << c.size() << " ";
		for(auto i=c.rbegin(); i!=c.rend(); i++) subs(b[0].size(), *i);
		// int res= subs(b[0].size(), *(--c.end()) );
		cout << r*b[1].size() + r + b[1].size() << endl;
		// for(int i=0; i<n; i++) printf("%d ", a[i]);
	}
}