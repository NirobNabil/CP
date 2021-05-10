#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int main(){
	int i, ix, t, n, x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	map<int, int> a;
	a[x]++;
	a[y]++;
	a[z]++;
	if(a[x] == 3) {
		printf("Equilateral Triangle\n");
	}else if(a[x]==2 || a[y]==2) {
		printf("Isosceles Triangle\n");
	}else {
		printf("Bad Triangle\n");
	}
}