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
	int i, ix, t, n;
	vector<pair<int,int> > a;
	scanf("%d", &t);
	while(t--){
		a.clear();
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &ix), a.push_back({ix,i+1});
		sort(a.begin(), a.end());
		// for(auto i:a) printf("%d\n", i.Y);
		int gg=0;
		for(int i=0; i<a.size(); i++) {
			if(i-1==-1 && a[i+1].X!=a[i].X) printf("%d\n", a[i].Y); 
			else if(i+1==a.size() && a[i-1].X!=a[i].X) printf("%d\n", a[i].Y);
			else if(a[i-1].X!=a[i].X && a[i+1].X!=a[i].X) {
				printf("%d\n", a[i].Y);
			}else continue;
			gg=1; break;
		}
		if(!gg) printf("-1\n");
	}
}