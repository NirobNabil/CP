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
	int i, ix, t, n, x,y;
	scanf("%d", &n);
	n++;
	t=n;
	vector<pair<int,int> > a;
	while(t--){
		scanf("%d %d", &x, &y);
		a.push_back({x,y});
	}
	a.push_back(a[1]);
	vector<char> d(4);
	if(a[n-2].X>a[n-1].X) d = {'W','E','N','S'};
	else d = {'E','W','S','N'};
	char cdir = 'N', ndir;
	int dt=0;
	// printf("%c %c %c %c\n", d[0], d[1], d[2], d[3]);
	for(int i=1; i<n; i++) {
		// printf("%d %d\n", a[i+1].X, a[i+1].Y);
		if(a[i+1].X>a[i].X) ndir='E';
		else if(a[i+1].X<a[i].X) ndir='W';
		else if(a[i+1].Y>a[i].Y) ndir='N';
		else ndir='S';
		switch(cdir) {
			case 'N':
				if(ndir==d[0]) dt++;
				// printf("%d %c %c %d\n", i,cdir,ndir, dt);
				break;
			case 'S':
				if(ndir==d[1]) dt++;
				// printf("%d %c %c %d\n", i,cdir,ndir, dt);
				break;
			case 'E': 
				if(ndir==d[2]) dt++;
				// printf("%d %c %c %d\n", i,cdir,ndir, dt);
				break;
			case 'W':
				if(ndir==d[3]) dt++;
				// printf("%d %c %c %d\n", i,cdir,ndir, dt);
				break;
		}
		cdir=ndir;
	}
	printf("%d\n", dt);
}