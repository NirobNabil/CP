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
	// #ifndef DDDEBUG
	// return;
	// #endif
	for(auto i:arr) cout << i.X << " " << i.Y << "\n";
	printf("\n");
}

int main(){
	int i, ix, t, n, x, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &x);
		rep(i, 0, n) scanf("%d", &a[i]);
		unsigned long long int ans=0;
		deque<pair<long long int,long long int> > q;
		for(int i=0; i<n; i++) q.push_back({a[i],1}); 
		while(!q.empty()) {
			if(q.front().X%x==0) {
				q.push_back({q.front().X/x,x*q.front().Y});
				// printf("%d %d\n", q.front().X, q.front().Y);
				// parr(q);
				ans += q.front().X * q.front().Y;
				q.pop_front();
			}else break; 
		}
		while(!q.empty()) {
			// printf("%d %d\n", q.front().X, q.front().Y);
			ans+=q.front().X * q.front().Y; 
			q.pop_front();
		}
		cout << ans << "\n";
	}
}