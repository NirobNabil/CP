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
	int i, ix, t, tt, n, a, b, k;
	scanf("%d", &t);
	while(t--){
		map<int,int> p,q,x,y;
		std::vector<int> va, vb;	
		scanf("%d %d %d", &a, &b, &k);
		for(int i=0; i<k*2; i++) {
			scanf("%d", &tt);
			if(i<k) va.push_back(tt);
			else vb.push_back(tt);
		}
		for(int i=0; i<k; i++) {
			x[va[i]]++;
			y[vb[i]]++;
		} 
		// for(auto i:p) printf("%d %d\n", i.X, i.Y);
		for(auto i:x) printf("%d %d\n", i.X, i.Y);
		printf("\n");
		for(auto i:y) printf("%d %d\n", i.X, i.Y);
		printf("\n");
		int ans=0;
		for(int i=0; i<k; i++)  {
			printf("%d %d\n", i, k-x[va[i]]-y[vb[i]]+1);
			ans += k-x[va[i]]-y[vb[i]]+1;
		}
		printf("%d\n", ans);
	}
}