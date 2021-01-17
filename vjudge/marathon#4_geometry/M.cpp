#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

//https://www.mathopenref.com/heronsformula.html
double triangle_area_sides(double a,double b,double c) {
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

//returns { m, c }
pair<double,double> get_line_eq(pair<double,double> a, pair<double,double> b) {
	double m = a.X==b.X?DBL_MAX:(a.Y-b.Y)/(a.X-b.X);
	return { m, m==DBL_MAX?DBL_MIN:(a.Y-a.X*m) };
}


// pair<double,double> point_along_line(pair<double,double> a, pair<double,double> b, double m, double c, double d) {
// 	return { a.X+(a.X<=b.X?1:-1)*(c<0?-1:1)*d*cos(atan(m)), a.Y+(a.Y<=b.Y?1:-1)*(c<0?1:-1)*d*sin(atan(m)) };
// }

pair<double,double> point_along_line(pair<double,double> a, pair<double,double> b, double m, double c, double d) {
	double l = m==DBL_MAX?0:(m==DBL_MIN?d:abs(d/sqrt(1+m*m)));
	double lx = m==DBL_MAX?d:(m==DBL_MIN?0:abs(m)*l);
	// cout << "xx " << (b.X<=a.X && b.Y>=a.Y) << endl;
	if(b.X<=a.X && b.Y>=a.Y) return { a.X-l, a.Y+lx };
	if(b.X>=a.X && b.Y>=a.Y) return { a.X+l, a.Y+lx };
	if(b.X<=a.X && b.Y<=a.Y) return { a.X-l, a.Y-lx };
	if(b.X>=a.X && b.Y<=a.Y) return { a.X+l, a.Y-lx };
}


bool pair_cmp(pair<double,double> a, pair<double,double> b) {
	return a.X==b.X && a.Y==b.Y;
}

void pair_prn(pair<double,double> a) {
	cout << a.X << ", " << a.Y << "\n";
}

double triangle_area_coo(pair<double,double> a, pair<double,double> b, pair<double,double> c) {
	if(pair_cmp(get_line_eq(a,b),get_line_eq(b,c))
		&& pair_cmp(get_line_eq(b,c),get_line_eq( c,a))) return 0;
	return abs((a.X*(b.Y-c.Y)+b.X*(c.Y-a.Y)+c.X*(a.Y-b.Y))/(double)2);
}

int main(){
	int n, a[S1];
	double x,y,d;
	std::vector<pair<double,double> > t(3), p;
	rep(i, 0, 3) {
		scanf("%lf %lf", &x, &y);
		t[i].X = x; t[i].Y = y;
	}
	rep(i, 0, 3) {
		scanf("%d", &n);
		auto [m,c] = get_line_eq(t[i], t[(i+1)%3]);
		// cout << t[i].X << "," << t[i].Y << " - ";
		// cout << t[(i+1)%3].X << "," << t[(i+1)%3].Y << "\n";
		for(int ix=0; ix<n; ix++) {
			scanf("%lf", &d);
			p.push_back(point_along_line(t[i],t[(i+1)%3],m,c,d));
			// cout << m << " " << c << "\n";
		}
	}
	int A = 0, B = 1, C = 2;
	n=p.size();
	int bA= A, bB= B, bC= C;
	while(1) {
	  while(1) {
	    while(triangle_area_coo(p[A], p[B], p[C]) <= triangle_area_coo(p[A], p[B], p[(C+1)%n]) ){
	      C = (C+1)%n;
	    }
	    if(triangle_area_coo(p[A], p[B], p[C]) <= triangle_area_coo(p[A], p[(B+1)%n], p[C]) ){ 
	      B = (B+1)%n;
	      continue;
	    } else break;
	  }
	  if( triangle_area_coo(p[A], p[B], p[C]) > triangle_area_coo(p[bA], p[bB], p[bC]) ) {
	    bA = A; bB = B; bC = C;
	  }

	  A = (A+1)%n;
	  if(A==B) B = (B+1)%n;
	  if(B==C) C = (C+1)%n;
	  if(A==0) break;
	}
	// for(auto i:p) {
	// 	cout << i.X << "," << i.Y << "\n";
	// }
	// printf("%d %d %d\n", bA, bB, bC);
	printf("%.6lf\n", triangle_area_coo(p[bA], p[bB], p[bC]));
}