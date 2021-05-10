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
	#ifndef DDDEBUG
	return;
	#endif
	for(auto i:arr) cout << i << " ";
	printf("\n");
}

void print(vector<int> v1, vector<int> v2) {
	int x=0;
	for(auto i:v1) {
		for(auto ix:v2) {
			if(i>ix) x++;
		}
	}
	printf("%d\n",x);
}

int main(){
	int i, ix, t, n, a[S1];
	vector<vector<int> > v;
	// v.push_back({9,5,1});
	// v.push_back({8,4,3});
	// v.push_back({7,6,2});
	v.push_back({16,11,6,1});
	v.push_back({15,12,5,2});
	v.push_back({14,10,7,3});
	v.push_back({13,9 ,8,4});
	for(int i=0; i<v.size(); i++) {
		for(int ix=0; ix<v.size(); ix++) {
			if(i==ix) continue;
			print(v[i], v[ix]);;
		}		
	} 
}