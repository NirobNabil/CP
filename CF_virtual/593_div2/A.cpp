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


int main(){
	int i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		int a, b, c, z=0;
		scanf("%d %d %d", &a, &b, &c);
		while(c>1 && b>0) z+=3, c-=2, b--;
		while(b>1 && a>0) z+=3, b-=2, a--;
		printf("%d\n", z);
	}
}