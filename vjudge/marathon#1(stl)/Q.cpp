#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// #define ch1(op1, op2) { printf("ggg\n"); }
#define ch1(op1, op2) { scanf("%d", &ix); if(q.size()!=n) { op1; op2; } else printf("The queue is full\n"); }
#define ch2(op1, op2) { if(q.size()!=0) { op1; op2; } else printf("The queue is empty\n"); }
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
	int i, ix, t, n, m, a[S1];
	string c;
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		deque<int> q;
		scanf("%d %d", &n, &m);
		printf("Case %d:\n", i);
		rep(i, 0, m) {
			cin >> c;
			if(c=="pushLeft") ch1(q.push_front(ix), printf("Pushed in left: %d\n", ix))
			else if(c=="pushRight") ch1(q.push_back(ix), printf("Pushed in right: %d\n", ix))
			else if(c=="popLeft") ch2(printf("Popped from left: %d\n", q.front()), q.pop_front())
			else if(c=="popRight") ch2(printf("Popped from right: %d\n", q.back()), q.pop_back())
		}
	}
}