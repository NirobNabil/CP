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
	int i, ix, t, n, px, py, u, d, r, l;
	string s;
	scanf("%d", &t);
	while(t--){
		u=0; d=0; r=0; l=0;
		s = "";
		scanf("%d %d", &px, &py);
		cin >> s;
		for(int i=0; i<s.length(); i++) {
			switch(s[i]) {
				case 'U': u++; break;
				case 'D': d--; break;
				case 'R': r++; break;
				case 'L': l--; break;
			}
		} 
		bool p = 1;
		// printf("%d %d %d %d\n", u, d, r, l);
		if(px<0 && l>px) p=0;
		if(px>0 && r<px) p=0;
		if(py<0 && d>py) p=0;
		if(py>0 && u<py) p=0;
		if(p) printf("YES\n");
		else printf("NO\n");
	}
}