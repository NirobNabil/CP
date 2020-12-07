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

int main(){
	int i, ix, t, n, k=20;
	while(scanf("%d", &n) && n!=0) {
		while(scanf("%d", &t)) {
			if(t==0) { printf("\n"); break;}
			queue<int> a, b;
			stack<int> c;
			rep(i,1,n+1) { a.push( i ); }
			b.push( t );
			rep(i,1,n) { scanf("%d", &t), b.push( t ); }
			while(!b.empty()) {
				if(c.empty() || c.top()!=b.front()) {
					if(a.empty()) { printf("No\n"); break; }
					// pv("a- ", a.front(), b.front(), (c.empty())?0:c.top());
					c.push(a.front());
					a.pop();
				}else {
					// pv("b- ", a.front(), b.front(), c.top());
					b.pop();
					c.pop();
				}
			}
			if(b.empty()) printf("Yes\n");
		}
	}
}