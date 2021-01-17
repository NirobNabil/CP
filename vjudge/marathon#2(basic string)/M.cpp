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
	int i, ix, t, n, is_num=0;
	string s,x;
	vector<string> a,b;
	cin >> s;
	for(int i=0; i<s.length(); i++) {
		if(s[i]!=',' && s[i]!=';') {
			x.push_back(s[i]);
		}else {
			// printf("%d\n", x.length());
			is_num=0;
			for(int ix=0; ix<x.length(); ix++) {
				if(x[0]=='0') {
					if(x.length()==1) is_num=1;
					else is_num=0;
					break;
				}
				if(x[ix]<'0' || x[ix]>'9') break;
				if(ix==x.length()-1) is_num=1;
				// printf("x[ix]=%c\n",x[ix]);
			} 
			if(is_num) a.push_back(x);
			else b.push_back(x); 
			x="";
		}
		// cout << "x- " << x << "\n";
	} 
	is_num=0;
	for(int ix=0; ix<x.length(); ix++) {
		if(x[0]=='0') {
			if(x.length()==1) is_num=1;
			else is_num=0;
			break;
		}
		if(x[ix]<'0' || x[ix]>'9') break;
		if(ix==x.length()-1) is_num=1;
		// printf("x[ix]=%c\n",x[ix]);
	} 
	if(is_num) a.push_back(x);
	else b.push_back(x); 
	x="";
	if(!a.size()) printf("-");
	else printf("\"");
	for(auto i=a.begin(); i!=a.end(); i++) cout << *i << ",\""[i==--a.end()];
	printf("\n");
	if(!b.size()) printf("-");
	else printf("\"");
	for(auto i=b.begin(); i!=b.end(); i++) cout << *i << ",\""[i==--b.end()];
	printf("\n");
}