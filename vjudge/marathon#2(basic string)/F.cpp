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
	int i, ix, t, n, a[S1];
	int arr[5][4];
	printf("%u\n", sizeof(arr[0]));
	for(int i=0; i<5; i++) {
		// printf("%u\n", sizeof(arr[0]));
		unsigned long long int g = (unsigned long long int)(arr+i);
		// printf("%d\n", g);
		int* x = (int*)g;
		// printf("%d\n", x);
		// printf("%d\n", x+1);
		// for(int ix=0; ix<4; ix++) printf("%u ", arr+ix);
		for(int ix=0; ix<4; ix++) scanf("%d", x+ix);
		// printf("\n");
	}
	for(int i=0; i<5; i++) {
		for(int ix=0; ix<4; ix++) printf("%d ", arr[i][ix]);
		printf("\n");
	}
}