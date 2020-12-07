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

int manh(int x,int y, int a, int b) {
	// printf("%d\n", abs(x-a)+abs(y-b));
	return abs(x-a)+abs(y-b);
}

int main(){
	int x,y, t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		unordered_map<int,unordered_map<int,int> > a;
		for(int i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			a[x][y]=1;
		}
		int gg=0, xd=0;
		for(auto i:a) {
			if(xd==1) break;
			for(auto ix:i.Y) {
						// printf("ll\n");
				for(auto xx:a){
						// printf("pp\n");
					if(gg==1) break;
					for(auto yy:xx.Y) {
						// printf("dd\n");
						if(gg==1) break;
						if(manh(i.X,ix.X,xx.X,yy.X)>k) gg=1;
					}
				}
				if(gg!=1) {
					printf("1\n");
					xd=1;
					break;
				}
				gg=0;
			}
		}
		if(xd==0) printf("-1\n");
	}
}