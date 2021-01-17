#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define point pair<double,double>

//https://www.mathopenref.com/heronsformula.html
double triangle_area_sides(double a,double b,double c) {
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}


//https://math.stackexchange.com/questions/2532427/formula-for-circumradius
double triangle_circumradius_sides(double a,double b,double c) {
	return (triangle_area_sides(a,b,c)==0)?
						0:(a*b*c)/(2*triangle_area_sides(a,b,c));
}


double get_line_len(point a, point b) {
	return sqrt( pow(a.X-b.X,2) + pow(a.Y-b.Y,2) );
}

double get_angle_side(double a, double b, double c) {
	return acos((a*a + b*b - c*c)/(2.0*a*b));
}

double get_angle_coo(point a, point b, point c) {
	double x = get_line_len(a,b);
	double y = get_line_len(b,c);
	double z = get_line_len( c,a );
	return get_angle_side(x,y,z);
}


int main(){
	int i, ix, t, nc, nt;
	double a[S1], x,y,z,c;
	std::vector<int> v;
	scanf("%d", &nc);
	rep(i, 0, nc) scanf("%lf", &a[i]);
	// rep(i, 0, nc) a[i] /= (double)2.0;
	scanf("%d", &nt);
	const double pi2 = acos(-1)/(double)2.0;
	for(int ix=0; ix<nt; ix++)  {
		t=0;
		v.clear();
		scanf("%lf %lf %lf", &x, &y, &z);
		double maxarm = max(x,max(y,z));
		c = triangle_circumradius_sides(x,y,z);
		// cout << get_angle_side(x,y,z) << " ";
		// cout << get_angle_side(y,z,x) << " ";
		// cout << get_angle_side(z,x,y) << " ";
		bool chk = get_angle_side(x,y,z) > pi2
						|| get_angle_side(y,z,x) > pi2
						|| get_angle_side(z,x,y) > pi2;
		// cout << chk << " " << maxarm << endl;
		for(int i=0; i<nc; i++) {
			if(a[i]>=c || (chk && a[i]>=maxarm) ) v.push_back(i);
		}
		if(v.size()) {
			printf("Peg %c will fit into hole(s): ", 'A'+ix);
			for(int i=0; i<v.size(); i++)  printf("%d%c", v[i]+1, i==v.size()-1?'\n':' ');
		}else printf("Peg %c will not fit into any holes\n", 'A'+ix);
	}
}