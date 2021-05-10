#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
	int i, ix, t, n;
	scanf("%d", &n);
	int l=1, h=n, tt=-1;
	bool side=1, on2=true;
	while(1) {
		printf("? %d %d\n", l,h);
		fflush(stdout);
		scanf("%d", &t);
		if(l+1 == h && (tt==-1 || t==tt || on2==false)) {
			printf("! %d\n", l==t?h:l);
			break;
		}
		if(tt==t || tt==-1) {
			if(t>=(l+h)/2) l=(l+h)/2, side=1;
			else h=(l+h)/2, side=0;
			on2=true;
			// printf("made on2 true\n");
		}else {
			int tl = l;
			l = l+(side==0?1:-1)*(h-l);
			h = h+(side==0?1:-1)*(h-tl);
			side != side;
			l = max(l,1);
			h = min(h,n);
			on2=false;
			// printf("made on2 false\n");
		}
		if(on2==false) tt=-1;
		else tt=t;
	}
}