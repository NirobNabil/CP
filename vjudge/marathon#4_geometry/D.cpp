	#include <bits/stdc++.h>
	using namespace std;
	#define ll long long int
	#define X first
	#define Y second
	#define A begin
	#define B end
	#define S1 100000
	#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

	struct pt {
	    double x, y;
	    pt(double a, double b) {
	    	x = a; y=b;
	    }
	};

	//returns { m, c }
	pt get_line_eq(pt a, pt b) {
		double m = a.x==b.x?DBL_MAX:(a.y-b.y)/(a.x-b.x);
		return { m, m==DBL_MAX?DBL_MIN:(a.y-a.x*m) };
	}

	bool pair_cmp(pt a, pt b) {
		return a.x==b.x && a.y==b.y;
	}

	void pair_prn(pt a) {
		cout << a.x << ", " << a.y << "\n";
	}

	double triangle_area_coo(pt a, pt b, pt c) {
		if(pair_cmp(get_line_eq(a,b),get_line_eq(b,c))
			&& pair_cmp(get_line_eq(b,c),get_line_eq( c,a))) return 0;
		return abs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/(double)2);
	}


	bool cmp(pt a, pt b) {
	    return a.x < b.x || (a.x == b.x && a.y < b.y);
	}

	bool cw(pt a, pt b, pt c) {
	    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
	}

	bool ccw(pt a, pt b, pt c) {
	    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
	}

	void convex_hull(vector<pt>& a) {
	    if (a.size() == 1)
	        return;

	    sort(a.begin(), a.end(), &cmp);
	    pt p1 = a[0], p2 = a.back();
	    vector<pt> up, down;
	    up.push_back(p1);
	    down.push_back(p1);
	    for (int i = 1; i < (int)a.size(); i++) {
	        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
	            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
	                up.pop_back();
	            up.push_back(a[i]);
	        }
	        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
	            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
	                down.pop_back();
	            down.push_back(a[i ]);
	        }
	    }

	    a.clear();
	    for (int i = 0; i < (int)up.size(); i++)
	        a.push_back(up[i]);
	    for (int i = down.size() - 2; i > 0; i--)
	        a.push_back(down[i]);
	}

	int main(){
		int n;
		double x,y,d;
		scanf("%d", &n);
		vector<pt> p;
		for(int ix=0; ix<n; ix++) {
			scanf("%lf %lf", &x, &y);
			p.push_back(pt(x,y));
			// cout << m << " " << c << "\n";
		}
		convex_hull(p);
		int A = 0, B = 1, C = 2;
		n=p.size();
		double mxarea = 0.0;
		int bA= A, bB= B, bC= C;
		while(A<n) {
		  while(B < n) {
		    while(C+1<n 
		    		&& triangle_area_coo(p[A], p[B], p[C]) < triangle_area_coo(p[A], p[B], p[C+1])){
		      C = C+1;
		    }
			  mxarea = max(mxarea, triangle_area_coo(p[A],p[B],p[min(C,n-1)]));
		    // if(triangle_area_coo(p[A], p[B], p[C]) < triangle_area_coo(p[A], p[B+1], p[C])){ 
		      B = B+1;
		    // } else break;
		  }
		  // if( triangle_area_coo(p[A], p[B], p[C]) > triangle_area_coo(p[bA], p[bB], p[bC]) ) {
		  //   bA = A; bB = B; bC = C;
		  // }

		  A = (A+1);
		  B = (A+1);
		  C = (A+2);
		  // if(A==0) break;
		}
		// for(auto i:p) {
		// 	cout << i.x << "," << i.y << "\n";
		// }
		// printf("%d %d %d\n", bA, bB, bC);
		printf("%.5lf\n", mxarea);
		return 0;
	}