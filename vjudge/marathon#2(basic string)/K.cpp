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

string v = "aeiouy";
stack<pair<char,int> > g;

int main(){
	int n;
	string s;
	cin >> n >> s;
	for(int i=0; i<s.length(); i++) {
		// printf("%c", s[i]);
		if(g.size() && s[i]!=g.top().X) {
			// printf("%d\n", g.size());
			if(g.size()==2 && (g.top().X=='e' || g.top().X=='o')) {
				while(g.size()) g.pop();
			}
			else {
				while(g.size()>1) {
					s.erase(g.top().Y,1);
					g.pop();
					i--;
				}
				g.pop();
			}
		} 
		if(v.find(s[i])!=string::npos) g.push({s[i],i});  
		// parr(g);
	} 
	// printf("\n");
	if(g.size()==2 && (g.top().X=='e' || g.top().X=='o')) n=n;
	else {
		while(g.size()>1) {
			s.erase(g.top().Y,1);
			g.pop();
		}
	}
	cout << s << "\n";
}