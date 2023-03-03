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

double dh, dl, dr, k, x, y, u, v, p, q;

double check(double x) {
	return sqrt( dh*dh + (dr-x)*(dr-x) ) + sqrt( dl*dl + x*x )*k;
}

double check2(double x) {
	return sqrt( dh*dh + (dr-x)*(dr-x) ) + sqrt( dl*dl + x*x );
}

int main(){
	int i, ix, t, n, a[S1];
	while(1){
		scanf("%lf", &dh);
		scanf("%lf", &dl);
		scanf("%lf", &dr);
		scanf("%lf", &k);
		if(dh==0.0 && dl==0.0 && dr==0.0 && k==0.0) break;
		double hi=dr, lo=0, mid;
		// int xx = 200;
		while(trunc(100.0*hi) != trunc(100.0*lo)) {
			// xx--;
			// mid = (hi+lo)/2.0;
			x = check(hi-(hi-lo)/3.0);
			y = check(lo+(hi-lo)/3.0);
			// printf("%.2lf %.2lf\n", trunc(100.0*lo), trunc(100.0*hi));
			// printf("%lf %lf\n", hi-(hi-lo)/3.0, x);
			// printf("%lf %.15lf\n", lo+(hi-lo)/3.0, y);
			if(x <= y) 
				lo = lo+(hi-lo)/3.0;
			if(y <= x)
				hi = hi-(hi-lo)/3.0;
			// printf("\n");
		}
		// printf("%d\n", xx);
		// printf("%lf %lf %lf\n", mid, lo, hi);
		printf("%.2lf\n", check2(lo));
	}
}