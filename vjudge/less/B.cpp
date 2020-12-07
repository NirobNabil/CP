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
	int i, ix, t, tm, n, k;
	scanf("%d", &t);
	while(t--){
		int c[100009];
		scanf("%d %d", &n, &k);
		rep(i, 0, n) scanf("%d", &c[i]);
		int m = INT_MAX;
		// for(int i=0; i<n; i++) printf("%d\n", c[i]);
		// printf("%d %d\n", n, k);
		for(ix=1; ix<=100; ix++) {
			int i = 0, tm=0;
			while(i<n) {
				// printf("%d %d %d\n", i, n, i<n);
				while(c[i]==ix && i<n) { i++; }
				if(i<n) {
					i = i+k;
					tm++;
				}
			}
			// if(t==0) printf("%d %d\n", ix, tm);
			m = min(m, tm);
		} 
		printf("%d\n", m);
	}
}