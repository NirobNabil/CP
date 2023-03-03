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

int chksubstr(string a, string b) {
	int ix=0;
	for(int i=0; i<a.length() && ix<b.length(); i++) {
		if(a[i]==b[ix]) ix++;
	} 
	return ix==b.length();
}

int chkswap(string a, string b) {
	for(int i=0; i<b.length(); i++) {
		// cout << a << endl;
		if(a.find(b[i])!=string::npos) {
			a.erase(a.find(b[i]),1);
		}else return 0;
		// cout << a << endl;
	} 
	return 1;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	if(chksubstr(s1,s2)) {
		printf("automaton\n");
	}else if(chkswap(s1,s2)) {
		if(s1.length()==s2.length()) printf("array\n");
		else printf("both\n");
	}else printf("need tree\n");
}