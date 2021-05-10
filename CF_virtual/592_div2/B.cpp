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

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		string s;
		cin >> s;
		int ta=0, f1=-1, l1=-1, ans=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='1') {
				if(f1==-1) f1=i;
				l1=i;
				ta++;
			}
		} 
		ans = n+ta;
		if(f1!=-1) ans = max(ans, (n-f1)*2);
		if(l1!=-1) ans = max(ans, (l1+1)*2);
		printf("%d\n", ans);
	}
}