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

int i, ix, n, m;
char x, y;
unordered_map<char, unordered_map<char, bool> > t;
map<char, bool> v;

int dfs(char i, char x) {
	// printf("%c\n", i);
	v[i] = 1;
	if(i==x) return 1;
	for(auto ix:t[i]) {
		if(!v[ix.X] && dfs(ix.X, x)) return 1;
	}
	return 0;
}

int main(){
	while(scanf("%d %d", &n, &m) != -1){
		// printf("%d %d\n", n, m);
		t.clear();
		rep(i, 0, n) {
			cin >> x >> y;
			// printf("%c %c\n", x, y);
			t[x][y] = 1;
		}
		string a, b;
		int la, lb;
		for(int i=0; i<m; i++)  {
			bool pos = true;
			cin >> a >> b;
			// cout << a << b << endl;
			la = a.length() ;   lb = b.length();
			if(la != lb) {
				pos = false;
			}else {
				for(int i=0; i<la; i++) {
					// printf("%c", a[i]);
					v.clear();
					if(dfs(a[i],b[i]) ) continue;
					else {
						pos = false;
						break;
					}
				}
			}
			if(pos) printf("yes\n");
			else printf("no\n");
		}
	}
}