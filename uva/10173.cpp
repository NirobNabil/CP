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
typedef complex<double> pt;
#define x real()
#define y imag()
#define dot(a,b) (conj(a)*b).x
#define cross(a,b) (conj(a)*b).y
#define dist(a,b) norm(a-b)
#define dist(a,b) norm(a-b)
#define angle(a,b) arg(b-a)
#define slope(a,b) tan(arg(b-a))
#define rotate(a,p,theta) ((a-p)*polar(1.0, theta)+p)
#define trigangle(a,b,c) abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))
#define projectonvector(p,v) (v * dot(p, v) / norm(v))  														 //project p to v
#define project(p,a,b) (a + (b - a) * dot(p - a, b - a) / norm(b - a)) //project p on line (a,b)
#define reflect(p,a,b) (a + conj((p - a) / (b - a)) * (b - a))
#define clkws(a,b,c) (angle(a,b) > angle(b,c)) 

//convert format
#define p2c(r,theta) polar(r, theta)
#define c2p(p) point(abs(p), arg(p))
#define r2d(r) (r*(180/M_PI))
#define d2r(d) (d*(M_PI/180))
point intersection(pt a, pt b, pt p, pt q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}
bool pcmp(pt a, pt b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y)
}

template<typename T>
int convexhull(vector<T>& in, vector<T>& a) {
	if(a.size()==1) return ;
	a = in;
	sort(a.begin(), a.end(), &pcmp);
	pt p1=a[0], p2=a.back();
	vector<pt> up, down;
	up.pb(p1);
	down.pb(p1);
	for(int i=0; i<a.size(); i++) {
		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while(down.size() >= 2 && cw(down[down.size()-2], down[down.size()-1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
	}
	a.clear();
  for (int i = 0; i < up.size(); i++)
      a.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; i--)
      a.push_back(down[i]);
}


int main(){
	// scanf("%d", &t);
	// while(t--){
	// 	scanf("%d", &n);
	// 	rep(i, 0, n) scanf("%d", &a[i]);
	point a={0,0}, b={1,1}, c={0,2};
	cout << trigangle(a,b,c) << " " 
			 << M_PI/2 << "\n"
			 << angle(a,b) << " "
			 << angle(b,c) << "\n"
			 << clkws(a,b,c) << "\n";
			 // << (a<b);
	set<int> gg={1,2};
	// }
}