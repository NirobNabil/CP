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
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	for(int ix=1; ix<=t; ix++) {
		scanf("%d", &n);
		char s[20];
		sprintf(s, "%d", n);
		int p = 1, g = strlen(s);
		for(int i=0; i<g/2; i++) {
			if(s[i] != s[g-i-1]) p = 0;
		} 
		printf("Case %d: %s\n", ix, p?"Yes":"No");
	}
}