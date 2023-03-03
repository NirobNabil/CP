#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int main(){
	int i, ix, t, n, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		string s;
		cin >> s;
		int p = 1;
		
		stack<int> t, m;
		for(int i=0; i<n && p!=0; i++) {
			if(s[i] == 'T') t.push(i);
			else {
				if(m.size() == t.size()) {
					p = 0;
				}else m.push(i);
			}
		}

		if( t.size() != m.size()*2 ) p = 0;

		for(int i=n-1; i>=0 && p!=0 && !m.empty(); i--) {
			if(s[i] == 'T') {
				if(m.top() > i) {
					p = 0;
					break;
				}else m.pop();
			}
		} 


		printf("%s\n", p ? "YES":"NO");
	}
}