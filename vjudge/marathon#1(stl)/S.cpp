#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define errr { printf("Error occurred\n"); exit(0); }
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

int i, ix, t, n, p=0, in=0, lp=0, li=0, gg=0;
string a,r="",br="";
vector<string> s;
int prr(int i) {
	int ix;
	gg=max(i,gg);
	if(i >= s.size()) errr
	if(s[i]=="pair") {
		r+="pair<";
		ix = prr(i+1);
		r+=",";
		ix = prr(ix+1);
		r+=">";
		return ix; 
	}else if(s[i]=="int") {
		r+="int";
		return i;
	}
	return 0;
}

int main(){
	scanf("%d", &n);
	while(!cin.eof()) {
		a="";
		cin >> a;
		if(a=="") break;
		s.push_back(a);
		// cout << a << endl;
	};
	prr(0);
	if(gg!=s.size()-1) errr
	// printf("%d %d\n", p,in);
	cout << r << br << "\n";
}

// pair int pair int int pair int