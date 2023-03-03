#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

// void pv(){ printf("\n"); }

// template<typename T, typename... Args>
// void pv(T a, Args... args) {
// 	#ifndef DDEBUG
// 	return;
// 	#endif
// 	std::cout << a << " "; pv(args...);
// }

// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {
// 	#ifndef DDEBUG
// 	return;
// 	#endif
// 	cout << *it << " = " << a << endl;
// 	err(++it, args...);
// }

// template<typename T>
// void parr(T arr) {
// 	#ifndef DDDEBUG
// 	return;
// 	#endif
// 	for(auto i:arr) cout << i << " ";
// 	printf("\n");
// }

int print(string x) {
	for(int i=0; i<x.length()-1; i++)  printf("%c ", x[i]);
	printf("%c", x.back());
	printf("\n");
	return 1;
}

unordered_map<char,int> m;
std::vector<string> v;
string a,b,s,g,h;
int dfs(int i) {
	if(h.length() && h[h.length()-1]!=b[h.length()-1]) return 0;
	if(h.length()==b.length() && h.compare(b)==0) { print(s); return 1; }
	if(i<a.length()) {
		g.push_back(a[i]);
		s.push_back('i');
		dfs(i+1);
		s.pop_back();
		g.pop_back();
	}
	if(g.length()) {
		char tmp = g.back();
		h.push_back(tmp);
		g.pop_back();
		s.push_back('o');
		// pv("1- ", b[h.length()-1], h.back(), tmp, s, h);
		dfs(i);
		h.pop_back();
		s.pop_back();
		g.push_back(tmp);
		// pv("r1-", h, s);
	}
	return 1;
}

int main(){
	int i, ix, t, n;
	char l[1000000];
	while(scanf("%s", l) != EOF){
		a = l;
		cin >> b;
		s="";
		g="";
		h="";
		v.clear();
		m.clear();
		printf("[\n");
		dfs(0);
		printf("]\n");
	}
}