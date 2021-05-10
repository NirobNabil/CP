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

int chk(string &s, string &r) {
	int ix = 0;
	for(int i=0; i<s.length(); i++) {
		if(s[i] == r[ix]) ix++;
	} 
	return ix >= r.length();
}

int main(){
	int i, ix, t, n, a[S1];
	cin >> t;
	for(int tc=0; tc<t; tc++) {
		cin >> n;
		vector<string> s(n);
		string g, r;
		
		for(int i=0; i<n; i++)  
			cin >> s[i];

		cin >> r;

		vector<int> ids;
		for(int i=0; i<n; i++)  {
			if(chk(s[i], r)) ids.pb(i);
		}
		
		printf("Case %d:\n", tc+1);
		if(ids.size()) {
			for(int i=0; i<ids.size(); i++)  
				printf("%d%c", ids[i]+1, " \n"[i==ids.size()-1]);
		}else {
			printf("No files found!\n");
		}
	}
}