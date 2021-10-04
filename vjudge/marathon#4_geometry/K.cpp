


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<vector<bool> > grid(1009,vector<bool>(1009));

void mark(int sx, int ex, int sy, int ey) {
	// printf("%d %d %d %d\n", sx,ex,sy,ey);
	for(int i=sy; i<=ey; i++) {
		for(int ix=sx; ix<=ex; ix++) {
			// printf("%d,%d\n", ix,i);
			grid[i][ix]=1;
		} 
	}
}

char checkDir(pair<int,int> a, pair<int,int> b) {
	if(a.X<b.X) return 'R';
	else if(a.X>b.X) return 'L';
	else if(a.Y<b.Y) return 'U';
	else return 'D';
}

int main(){
	int i, ix, t, n;
	int x,y;
	pair<int,int> a[S1];
	scanf("%d", &n);
	int mxx=0, mxy=0;
	int mnx=INT_MAX, mny=INT_MAX;
	rep(i, 0, n) {
		scanf("%d %d", &x, &y);
		a[i] = {x,y};
		mxx = max(x,mxx);
		mxy = max(y,mxy);
		mnx = min(x,mnx);
		mny = min(y,mny);
	}
	int ds=0, de=0;
	for(int i=2; i<n+2; i++) {
		ds=0, de=0;
		if(a[i-1].Y == a[i%n].Y) {
			if(a[i-2].Y > a[i-1].Y) ds=1;
			if(a[(i+1)%n].Y > a[i%n].Y) de=1;
			
			if(a[i-1].X<a[i].X) {
				mark( a[i-1].X+ds, a[i%n].X-de, a[i%n].Y+1, mxy);
			} else {
				mark( a[i%n].X+!de, a[i-1].X-!ds, mny, a[i%n].Y-1);
			}
		}else {
			if(a[i-2].X > a[i-1].X) ds=1;
			if(a[(i+1)%n].X > a[i%n].X) de=1;

			if(a[i-1].Y<a[i%n].Y) {
				mark( mnx, a[i%n].X-1, a[i-1].Y+!ds, a[i%n].Y-!de);
			} else {
				mark( a[i%n].X+1, mxx, a[i%n].Y+de, a[i-1].Y-ds);
			}
		}
	}
	for(int i=0; i<n; i++) {
		string s = {checkDir(a[i],a[(i+1)%n]), checkDir(a[(i+1)%n],a[(i+2)%n]), checkDir(a[(i+2)%n],a[(i+3)%n])};
		if(s=="URD") {
			mark(mnx, mxx, a[(i+1)%n].Y+1, mxy);
		}else if(s=="RDL") {
			mark(a[(i+1)%n].X+1, mxx, mny, mxy);
		}else if(s=="DLU") {
			mark(mnx, mxx, mny, a[(i+1)%n].Y-1);
		}else if(s=="LUR") {
			mark(mnx, a[(i+1)%n].X-1, mny, mxy);
		}
	}	
	for(int i=mny; i<=mxy; i++) {
		for(int ix=mnx; ix<=mxx; ix++) {
			if(grid[i][ix]==0) {
				printf("SAFETY\n");
				return 0;
			}
		}
		// printf("\n");
	}
	printf("DANGER\n");
}