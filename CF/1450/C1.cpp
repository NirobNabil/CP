#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define CEIL(n,x) ((n%x>0)?n/x+1:n/x)
char g[309][309];
// int a[] = {-1,0,1};
int n;
#define CHK(a,b,x,y,p,q) (g[a][b]==g[x][y] && g[p][q]==g[x][y] && g[a][b]==g[p][q])
#define CHKX(a,b,x,y,p,q) (g[a][b]=='X' && g[x][y]=='X' && g[p][q]=='X') 

int ch(int x, int y){	
	// int v=0;
	if(x<n && x>=0 && y<n && y>=0 && g[x][y]=='X') {
		return 1;
	}else return 0;
}

int check(int x, int y){
	int gg=0;
	// if(y<n && y>0) gg += CHK(x,y-1,x,y-1,x,y+1) && CHKX(x,y-1,x,y,x,y+1);
	// if(x<n && x>0) gg += CHK(x-1,y,x,y,x+1,y) && CHKX(x-1,y,x,y,x+1,y);
	// if(y<n && y>0) for(int i=(x==0?1:0); i<min(3,n-x+1); i++) gg+=(CHK(x+a[i],y-1,x+a[i],y,x+a[i],y+1) && CHKX(x+a[i],y-1,x+a[i],y,x+a[i],y+1));
	// if(x<n && x>0) for(int i=(y==0?1:0); i<min(3,n-y+1); i++) gg+=(CHK(x-1,y+a[i],x,y+a[i],x+1,y+a[i]) && CHKX(x-1,y+a[i],x,y+a[i],x+1,y+a[i]));
	// gg += (g[x-1][y-1]=='X' && g[x][y]=='X' && g[x+1][y+1]=='X');
	// gg += (g[x-1][y+1]=='X' && g[x][y]=='X' && g[x+1][y-1]=='X');
	// int i=1;
	gg += (ch(x,y-1) && ch(x,y) && ch(x,y+1) );
	gg += (ch(x-1,y) && ch(x,y) && ch(x+1,y) );
	gg += (ch(x,y) && ch(x,y+1) && ch(x,y+2) );
	gg += (ch(x,y) && ch(x,y-1) && ch(x,y-2) );
	gg += (ch(x,y) && ch(x+1,y) && ch(x+2,y) );
	gg += (ch(x,y) && ch(x-1,y) && ch(x-2,y) );
	// printf("%d %d %d\n", x,y,CHKX(x+a[i],y-1,x+a[i],y,x+a[i],y+1));
	return gg;
}


// int r=0;
int se(int x,int y) {
	if(x<n && x>=0 && y<n && y>=0 && check(x,y)) g[x][y]='O';
	return 0;
	// if(g[i*3+iy][ix*3+iy]!='.') g[i*3+iy][ix*3+iy]='O';
}


int main(){
	int i, ix, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", g[i]);
		}
		// printf("%d\n", CEIL(4,3));
		if(n<3) {
			for(int i=0; i<n; i++) printf("%s\n", g[i]);
		}else {
		  for(int i=0; i<CEIL(n,3); i++) {
		  	for(int ix=0; ix<CEIL(n,3); ix++) {
			  	for(int iy=0; iy<3; iy++) se(i*3+iy, ix*3+iy);
		  	}
		  }	
			for(int i=0; i<n; i++) {
				printf("%s", g[i]);
				printf("\n");
			}
		}
	}
}