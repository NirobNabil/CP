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

string s;

int main(){
	int ans, i, ix, t, n, a[S1];
	stack<int> g;
	scanf("%d", &t);
	while(t--){
		ans=0;
		cin >> s;
		if(s.length()<3) {
			if(s.length()==2 && s[0] == s[1]) ans=1;
		}else{
			for(int i=0; i<s.length()-2; i++) {
				// printf("%d\n", i);
				if(s[i]==s[i+1] && s[i+1]==s[i+2]) {
					for(ix=i; ix<s.length()-1 && s[ix]==s[ix+1]; ix++) {
						if((ix+1-i)%3==1 || (ix+1-i)%3==2) g.push(ix+1);
					}
					// printf("%d\n", i);
					while(!g.empty()) s[g.top()]='*', g.pop();
					i=ix-1;

				}
				else if(s[i]==s[i+1]) s[i+1]='*';
				else if(s[i]==s[i+2]) s[i+2]='*';
				else if(s[i+1]==s[i+2]) s[i+2]='*';
				// else if(s[i]==s[i+1]) s[i]='*';
			}
		}
		for(int i=0; i<s.length(); i++) { if(s[i]=='*') ans++; } 
		printf("%d\n", ans);
		// cout << s << "\n";
	}
}