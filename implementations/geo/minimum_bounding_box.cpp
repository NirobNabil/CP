#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define dt double
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
struct point{
	dt x,y;
	point operator + (const point &b) { return point(x+b.x, y+b.y); }
	point operator - (const point &b) { return point(x-b.x, y-b.y); }
	point operator * (dt &m) { return point(x*m, y*m); }
	point operator / (dt &m) { return point(x/m, y/m); }
	dt cross (const point &b) {return }
};
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


int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &a[i]);
		
	}
}