#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define vp vector<pair<int,int>>
#define pp pair<int,int>

#define pb(x) emplace_back(x)
#define in(x) insert(x)
#define del(x) erase(x)

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000



int main(){
	int i, ix, t, n, a, b, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		map<char,int> c;
		scanf("%d %d", &a, &b);
		c['0'] = a;
		c['1'] = b; 
		string s;
		cin >> s;
		n = a+b;
		stack<pp> ss;

		int p = 1;

		for(int i=0; i<n/2; i++) {
			if(s[i] == '?' && s[n-i-1] == '?') {
				continue;
			} else {
				if( s[i] == '?' ) {
					s[i] = s[n-i-1];
				} else if( s[n-i-1] == '?' ) {
					s[n-i-1] = s[i];
				} else if( s[i] != s[n-i-1] ) {
					p = 0;
				}

				c[s[i]]--;
				c[s[n-i-1]]--;
			}
		} 

		for(int i=0; i<n/2; i++) {
			if(s[i] == '?') {
				if(c['0']>1) {
					s[i] = s[n-i-1] = '0';
					c['0']-=2;
				}else if(c['1']>1) {
					s[i] = s[n-i-1] = '1';
					c['1']-=2;
				} else {
					p = 0;
				}
			}
		} 


		if( n % 2 == 1 ) {
			int i = n/2;
			if( s[i] != '?' ) c[s[i]]--;
			else {
				if(c['0'] > c['1']) c['0']--, s[i] = '0';
				else c['1']--, s[i] = '1';
			}
		}

		p = min(p, (int)(c['0'] >= 0 && c['1'] >= 0));
		if(p) cout << s << "\n";
		else printf("-1\n");

	}
}