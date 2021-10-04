#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 200000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

void pv(){ printf("\n"); }

template<typename T, typename... Args>
void pv(T a, Args... args) {
	#ifndef DDEBUG
	return;
	#endif
	std::cout << a << " "; pv(args...);
}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	#ifndef DDEBUG
	return;
	#endif
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

template<typename T>
void parr(T arr) {
	#ifndef DDEBUG
	return;
	#endif
	for(auto i:arr) cout << i << " ";
	printf("\n");
}

int main(){
	int i, ix, t, n;
	vector<int> a;
	map<int, set<int> > occ;
	map<int, int> op;
	scanf("%d", &t);
	while(t--){
		a.clear();
		op.clear();
		occ.clear();
		scanf("%d", &n);
		rep(i, 0, n) {
			scanf("%d", &ix);
			if(a.empty()) a.push_back(ix);
			else if(a.back()!=ix) a.push_back(ix);
		}
		// parr(a);
		n = a.size();
		for(int i=0; i<n; i++) {
			// if( occ.find(2)!=occ.end()) printf("x- %d ", a[i]);
			if(i==n-1 && occ.find(a[i])!=occ.end()) continue;
			else occ[a[i]].insert(i);
		}
		if(n==1) {
			printf("%d\n", 0);
			continue;
		}
		for(auto i:occ) {
			// printf("x- %d %d\n", i.X, i.Y.size());
			if(i.Y.find(0)!=i.Y.end() || i.Y.find(n-1)!=i.Y.end()) {
				op[i.Y.size()]++;  
			}else op[i.Y.size()+1]++;
		}
		printf("%d\n", op.begin()->X);
		// for(auto i:occ) printf("%d ", i.X);
		// printf("\n");
	}
}