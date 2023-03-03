#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

double don0(int sal) {
	return 0.0;
}

double donA(double sal) {
	return max(0.0,(sal-25000))*(0.1);
}

double donB(double sal) {
	double a=0;
	if(sal>50000) {
		a += 25000*.1 + max(0.0, (sal-50000)*.15);
	}else a = max(0.0, (sal-25000)*.1);
	return a;
}

double donC(double sal) {
	double a=0;
	if(sal>50000) {
		a += 25000*.1;
		if(sal>100000) {
			a += 50000*.15 + (sal-100000)*.2;
		}else a += (sal-50000)*.15;
	}
	return a;
}

double donD(double sal) {
	return (sal)*.2;
}


int main(){
	double sal;
	cin >> sal;
	if(sal<=25000) cout << don0(sal);
	else if(sal <= 50000) cout << donA(sal);
	else if(sal <= 100000) cout << donB(sal);
	else if(sal <= 200000) cout << donC(sal);
	else cout << donD(sal);
}