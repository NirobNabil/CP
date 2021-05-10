#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int i, ix, t, n, k, a[S1], b[S1];

int check(int i) {
	if(i>=n) return 0;
	if(b[i]!=-1) return b[i];
	int ch=INT_MAX;
	// printf("called %d\n", i);
	for(int ix=1; ix<=k; ix++) {
		if(i+ix>=n) break;
		// printf("%d ", abs(a[i]-a[i+ix]) + check(i+ix));
		ch = min(ch,abs(a[i]-a[i+ix]) + check(i+ix));
	}
	// printf("- %d", i);
	// printf("- %d\n", ch);
	// printf("%d %d %d\n", i,ch1,ch2);
	b[i] = ch;
	return b[i];
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		b[i] = -1;
	}
	b[n-1] = 0;
	// b[n-2] = abs(a[n-1]-a[n-2]);
	cout << check(0) << endl;
}