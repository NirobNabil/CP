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
	double x1,x2,r1,x2,y2,r2,a,b,c;
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	scanf("%lf %lf %lf", &x2, &y2, &r2);
	if(x1==x2 && y1==y2 && r1==r2) printf("THE CIRCLES ARE THE SAME\n");
	else if(-2.0*(y1-y2)==0.0) printf("NO INTERSECTION\n");
	else {
		x^2-2xa+a^2+y^2-2yb+b^2-r^2
		x^2+x(-2a)+
		y = -\frac{r1*r1-r2*r2-x1*x1+x2*x2-y1*y1+y2*y2+2ax-2cx}{2\left(b-d\right)}
		a = 1;
		b = -2.0*x1;
		c = a*a + 		
	} 
}