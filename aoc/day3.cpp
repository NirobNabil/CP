#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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

int main(){
	ll i, ix, n, a, ans=1;
	vector<string> map;
	string t;	
	while(cin >> t) {
		map.push_back(t);
	}	
	for(auto &i:map) {
		while(i.length()<=(map.size()*8)) i+=i;
	}
	vector<pair<int,int> > gg = {{1,1},{3,1},{5,1},{7,1},{1,2}};
	for(ix=0; ix<5; ix++) {
		for(a=0, i=0, n=0; i<map.size(); i+=gg[ix].Y, n+=gg[ix].X) a += map[i][n]=='#'?1:0;
		printf("%d\n",a);
		ans *= a;
	} 
	printf("%lld\n", ans);
}