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
	while(t--){
		string a, b, c;
		scanf("%d", &n);
		cin >> a >> b;
		vector<bool> p(n);
		int x = 0;

		for(int i=0; i<a.size(); i++) {
			c.push_back(a[i]==b[i]?'0':'1');
			if(a[i] == '1') x++;
			else x--;
			if(x==0) p[i] = 1;
			else p[i] = 0;
		}
		
		int g = c[0];
		for(int i=0; i<n; i++) {
			if(g != c[i]) {
				printf("NO\n");
				break;
			}
			if(i<n-1 && p[i] == 1) g = c[i+1];
			else if(i==n-1) {
				if(p[i] == 0 && g != '0') printf("NO\n");
				else printf("YES\n");
			}
		}

	}
}