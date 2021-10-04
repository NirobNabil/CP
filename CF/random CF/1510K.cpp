#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int i, ix, t, n, x, y, z;
vector<int> a;

void op1(vector<int> &v) {
	for(int i=0; i<2*n; i+=2) {
		swap(v[i], v[i+1]);
	} 
}

void op2(vector<int> &v) {
	for(int i=0; i<n; i++) {
		swap(v[i], v[n+i]);
	}
}

int check(int xx) {
	vector<int> v = a;
	if(xx) op2(v);
	if(is_sorted(v.A(), v.B())) return xx+0;

	int i=1;
	for(; i<2*n; i+=2) {
		op1(v);
		if(is_sorted(v.A(), v.B())) return xx+i;
		
		op2(v);
		if(is_sorted(v.A(), v.B())) return xx+i+1;
	} 

	if(!xx) {
		op2(v);
		if(is_sorted(v.A(), v.B())) return i-1;
	}
	return -1;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<2*n; i++) {
      scanf("%d", &x);
      a.pb(x);
  }

  x = check(0);
  y = check(1);

  if(x == -1) printf("%d\n", y);
  else if(y == -1) printf("%d\n", x);
  else printf("%d\n", min(x,y));
 
}