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

string s;
map<char,pair<int,int> > lp;
int cx=0, cy=0;

void step(int &c, int add, int o) {
	if( c + add == o ) return;
	else c += add;
}

pair<int,int> follow(int ox, int oy, int g=0) {
	for(int i = 0; i < s.size(); i++) {
		switch(s[i]) {
			case 'U':
				step(cy, 1, oy); break;
			case 'D':
				step(cy, -1, oy); break;
			case 'R':
				step(cx, 1, ox); break;
			case 'L':
				step(cx, -1, ox); break;
		}
		if(g==1) lp[i] = {cx, cy};
	} 
	return {cx, cy};
}

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		cx = 0;  cy = 0;
		lp.clear();
		cin >> s;
		lp[0] = {0,0};
		follow(0,0,1);
		int pos = -1;
		for(auto i:lp) cout << i.Y.X << ", " << i.Y.Y << "\n";
		for(int i=0; i<n; i++) {
			auto [x, y] = follow(lp[i].X, lp[i].Y);
			if(x==0 && y==0) {
				pos = i;
				break;
			}
		}
		if(pos != -1) 
			printf("%d %d\n", lp[pos].X, lp[pos].Y);
		else 
			printf("0 0\n");
	}
}