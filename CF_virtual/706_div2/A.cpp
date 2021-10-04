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
	int i, ix, t, n, k, a[S1];
	scanf("%d", &t);
	while(t--){
		string s;
		scanf("%d %d", &n, &k);
		cin >> s;
		int pos = 1;
		if(n%2==0 && k==n/2) pos=0;
		for(int i=0; i<k; i++) {
			if(s[i] == s[s.length()-i-1]) continue;
			else { pos=0; break; }
		}
		printf("%s\n", pos?"YES":"NO");
	}
}