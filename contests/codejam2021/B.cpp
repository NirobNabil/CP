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

// int chk(int i) {
// 	int c = 0;
// 	for(int i=0; i<st.length() && st[i]!='?'; i++) {
// 		if(st[i] == 'C' && i+1 < n && st[i+1] == 'J') c+=x;
// 		if(st[i] == 'J' && i+1 < n && st[i+1] == 'C') c+=y;
// 	} 
// 	if(s[i] == '?') {
// 		if(i-1 < 0 ) return c;
// 		if(i+1 >= n ) return c;
// 		if(s[i])
// 	}
// }

int main(){
	int i, ix, t, n, a[S1], x, y;
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++) {
		scanf("%d %d", &x, &y);
		string s, st;
		cin >> s;
		for(int i=0; i<s.length(); i++) {
			if(st == "" || st.back() != s[i]) st.pb(s[i]);
		} 
		int c = 0;
		for(int i=0; i+1<st.length(); i++) {
			if(st[i] == '?' && i-1>=0 && s[i-1] != s[i+1]) 
				c += (st[i-1]=='J'?y:x);
			if(st[i] == 'C' && st[i+1] == 'J') c+=x;
			if(st[i] == 'J' && st[i+1] == 'C') c+=y;
		} 
		// for(auto i:st) printf("%c", i);
		// printf("\n");
		printf("Case #%d: %d\n", tc, c );
	}
}