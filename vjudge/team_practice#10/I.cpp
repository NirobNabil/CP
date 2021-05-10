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
	int i, ix, t, n, a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	int price = 0;
	
	for(int i=0; i<3; i++) {
		if(a[i] >= 500) price += a[i]-100, a[i] = 0;
	} 

	// printf("%d\n", price);
	// for(int i=0; i<3; i++) printf("%d ", a[i]);
	// printf("\n"); 

	if(a[0] + a[1] + a[2] >= 500) {
		price += a[0] + a[1] + a[2] - 100;
	}else price += a[0] + a[1] + a[2];

	printf("%d\n", price);

}