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

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main(){
	int i, ix, t, n, a[S1];
	string s1,s2;
	cin >> s1 >> s2;
	for(int i=0; i<s1.length(); i++) {
		if((s1[i]-'A')%32==(s2[i]-'A')%32) continue;
		if(lexicographical_compare(s1.c_str(),s1.c_str()+s1.length(),s2.c_str(),s2.c_str()+s2.length(),mycomp)) {
			printf("-1\n");
		}else printf("1\n");
		return 0;
	} 
	printf("0\n");
	return 0;
}