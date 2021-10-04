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
// typedef complex<double> point;
// #define x real()
// #define y imag()
// #define dot(a,b) (conj(a)*b).x
// #define cross(a,b) (conj(a)*b).y
// #define dist(a,b) norm(a-b)
// #define dist(a,b) norm(a-b)
// #define angle(a,b) arg(b-a)
// #define slope(a,b) tan(arg(b-a))
// #define p2c(r,theta) polar(r, theta)
// #define c2p(p) point(abs(p), arg(p))
// #define rotate(a,p,theta) ((a-p)*polar(1.0, theta)+p)
// #define trigangle(a,b,c) abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))
// #define projectonvector(p,v) (v * dot(p, v) / norm(v))  														 //project p to v
// #define project(p,a,b) (a + (b - a) * dot(p - a, b - a) / norm(b - a)) //project p on line (a,b)
// #define reflect(p,a,b) (a + conj((p - a) / (b - a)) * (b - a))
// point intersection(point a, point b, point p, point q) {
//   double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
//   return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
// }
using dt = double;

struct point{
	dt x,y;
	point(double a = 0,double b = 0) {x=a, y=b;}
	point operator + (const point &rhs) {return point(x+rhs.x,y+rhs.y);}
	point operator - (const point &rhs) {return point(x-rhs.x,y-rhs.y);}
	point operator * (dt m) {return point(x*m, y*m);}
	point operator / (dt m) {return point(x/m, y/m);}
	dt cross(const point &p){return (x*p.y - y*p.x);}
	dt dot(const point &p) {return (x*p.x+y*p.y);}
	bool operator < (const point &rhs) {return x<rhs.x|| (x==rhs.x && y<rhs.y);}
	dt dis(const point &rhs) {return hypot(x-rhs.x,y-rhs.y);}
	dt area(point a,point b){
		return (a-*this).cross(b-*this);
	}
	void print(bool lb=true){
		scanf("%lf %lf%c", &x,&y,lb?'\n':' ');
	}
};

int orientation(point p1, point p2, point p3) 
{ 
  // subtracting slope of p1p2 from p2p3 to check if slope 
  // of p2p3 is greater than p1p2  
  int val = (p2.y - p1.y) * (p3.x - p2.x) - 
            (p2.x - p1.x) * (p3.y - p2.y); 

  if (val == 0) return 0;  // colinear 

  return (val > 0)? 1: 2; // clock or counterclock wise 
} 

// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool on_segment(point p, point r, point q) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int on_line(point p1, point q1, point p2) {
	return orientation(p1,p2,q1)==0 && on_segment(p1,q1,p2);	
}

bool line_intersect(point p1, point q1, point p2, point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (  on_line(p1,q1,p2)
    	 || on_line(p1,q1,q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

// void convex_hull(vector<point> &grid) {

// }

int main(){
	// int i, ix, t, n, a[S1];
	point a=point(0,0), b=point(2,2), c=point(3,3), d=point(4,4);
	cout << line_intersect(a,c,sheb,d);
}