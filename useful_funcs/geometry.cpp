#define point pair<double,double>

//https://www.mathopenref.com/heronsformula.html
double triangle_area_sides(double a,double b,double c) {
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}


//returns { m, c }
point get_line_eq(point a, point b) {
	double m = a.X==b.X?DBL_MAX:(a.Y-b.Y)/(a.X-b.X);
	return { m, m==DBL_MAX?DBL_MIN:(a.Y-a.X*m) };
}


// point point_along_line(point a, point b, double m, double c, double d) {
// 	return { a.X+(a.X<=b.X?1:-1)*(c<0?-1:1)*d*cos(atan(m)), a.Y+(a.Y<=b.Y?1:-1)*(c<0?1:-1)*d*sin(atan(m)) };
// }

point point_along_line(point a, point b, double m, double c, double d) {
	double l = m==DBL_MAX?0:(m==DBL_MIN?d:abs(d/sqrt(1+m*m)));
	double lx = m==DBL_MAX?d:(m==DBL_MIN?0:abs(m)*l);
	// cout << "xx " << (b.X<=a.X && b.Y>=a.Y) << endl;
	if(b.X<=a.X && b.Y>=a.Y) return { a.X-l, a.Y+lx };
	if(b.X>=a.X && b.Y>=a.Y) return { a.X+l, a.Y+lx };
	if(b.X<=a.X && b.Y<=a.Y) return { a.X-l, a.Y-lx };
	if(b.X>=a.X && b.Y<=a.Y) return { a.X+l, a.Y-lx };
}


bool pair_cmp(point a, point b) {
	return a.X==b.X && a.Y==b.Y;
}

void pair_prn(point a) {
	cout << a.X << ", " << a.Y << "\n";
}

double triangle_area_coo(point a, point b, point c) {
	if(pair_cmp(get_line_eq(a,b),get_line_eq(b,c))
		&& pair_cmp(get_line_eq(b,c),get_line_eq(c,a))) return 0;
	cout << pair_cmp(get_line_eq(a,b),get_line_eq(b,c)) << endl;
	cout << pair_cmp(get_line_eq(b,c),get_line_eq(c,a)) << endl;
	pair_prn(get_line_eq(a,b));
	pair_prn(get_line_eq(b,c));
	pair_prn(get_line_eq(c,a));
	return abs((a.X*(b.Y-c.Y)+b.X*(c.Y-a.Y)+c.X*(a.Y-b.Y))/(double)2);
}

double get_line_len(point a, point b) {
	return sqrt( pow(a.X-b.X,2) + pow(a.Y-b.Y,2) )
}

double get_angle_coo(point a, point b, point c) {
	double [x,y,z] = {get_line_len(a,b),get_line_len(b,c),get_line_len(c,a)};
	return acos((a*a + b*b - c*c)/(2.0*a*b))
}


char checkDir(pair<int,int> a, pair<int,int> b) {
	if(a.X<b.X) return 'R';
	else if(a.X>b.X) return 'L';
	else if(a.Y<b.Y) return 'U';
	else return 'D';
}
