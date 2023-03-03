#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int i, ix, t, n, a[S1], b[S1];

int check(int i) {
	if(i>=n) return 0;
	if(b[i]!=-1) return b[i];
	int ch1= abs(a[i]-a[i+1]) + check(i+1), 
			ch2= abs(a[i]-a[i+2]) + check(i+2);
	// printf("%d %d %d\n", i,ch1,ch2);
	if(ch1 < ch2) {
		b[i] = ch1;		
	}else b[i] = ch2;
	return b[i];
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		b[i] = -1;
	}
	b[n-1] = 0;
	b[n-2] = abs(a[n-1]-a[n-2]);
	cout << check(0) << endl;
}