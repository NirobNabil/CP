#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define A first
#define Y second
#define A begin
#define B end
#define S1 100009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef complex<double> point;
#define x real()
#define y imag()
#define dot(a,b) (conj(a)*b).x
#define cross(a,b) (conj(a)*b).y
#define dist(a,b) norm(a-b)
#define dist(a,b) norm(a-b)
#define angle(a,b) arg(b-a)
#define slope(a,b) tan(arg(b-a))
#define p2c(r,theta) polar(r, theta)
#define c2p(p) point(abs(p), arg(p))
#define rotate(a,p,theta) ((a-p)*polar(1.0, theta)+p)
#define trigangle(a,b,c) abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))
#define projectonvector(p,v) (v * dot(p, v) / norm(v))  														 //project p to v
#define project(p,a,b) (a + (b - a) * dot(p - a, b - a) / norm(b - a)) //project p on line (a,b)
#define reflect(p,a,b) (a + conj((p - a) / (b - a)) * (b - a))
point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}


int i, ix, t, n;
std::vector<int> a(S1),b(S1);

int main(){
	scanf("%d", &t);
	while(t--){
		a.clear();
		b.clear();
		scanf("%d", &n);
		rep(i, 1, n+1) {
			scanf("%d", &a[i]);
		}
		for(int i=n; i>0; i--) {
			b[i] = 1;
			for(int ix=i+i; ix<=n; ix+=i) {
				if(a[i]<a[ix]) b[i]=max(b[i],1+b[ix]);
			}
		}
		for(int i=2; i<=n; i++) {
			if(a[1]<a[i]) b[1]=max(b[1], 1+b[i]); 
		}
		int mm=0;
		for(int i=1; i<=n; i++) mm=max(b[i],mm);
		printf("%d\n",mm);
	}
}