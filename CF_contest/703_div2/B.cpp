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
#define CEIL(a,b) (a%b?a/b+1:a/b)
#define ABS(a) (a<0?a*-1:a)

using dt = double;

struct point{
	ll x,y;
	point(ll a = 0,ll b = 0) {x=a, y=b;}
	bool operator == (const point &rhs) {return rhs.x==x && rhs.y==y;}
	ll dism(const point &rhs) {return abs(x-rhs.x)+abs(y-rhs.y);}
	void print(bool lb=true){
		printf("%lld %lld%c", x,y,lb?'\n':' ');
	}
};


vector<point> a;

ll chk(ll x, ll y) {
	ll ans=0;
	// printf("f - %d %d\n", x,y);
	point pp=point(x,y);
	for(int i=0; i<a.size(); i++) {
		ans += a[i].dism(pp);
		// printf("%d,%d - %lld\n", a[i].x, a[i].y, a[i].dism(pp));
	} 
	// printf("\n");
	return ans;
}

int main(){
	ll i, ix, t, n, x,y;
	std::vector<ll> xs, ys;
	scanf("%lld", &t);
	while(t--){
		a.clear();
		xs.clear();
		ys.clear();
		scanf("%lld", &n);
		ll avgx=0, avgy=0, mxx=0, mxy=0, mnx=LONG_MAX, mny=LONG_MAX;
		for(int i=0; i<n; i++) {
			scanf("%lld %lld", &x, &y);
			a.pb(point(x,y));
			avgx += x;  				avgy += y;	
			mnx = min(mnx, x);  mxx = max(mxx, x);
			mny = min(mny, y);  mxy = max(mxy, y);
		}
		xs.pb(avgx/n);
		xs.pb(avgx/n -1);
		xs.pb(avgx/n +1);
		xs.pb(mxx - (xs[0]-mnx));
		xs.pb(mxx - (xs[1]-mnx));
		xs.pb(mxx - (xs[2]-mnx));
		ys.pb(avgy/n);
		ys.pb(avgy/n -1);
		ys.pb(avgy/n +1);
		ys.pb(mxy - (ys[0]-mny));
		ys.pb(mxy - (ys[1]-mny));
		ys.pb(mxy - (ys[2]-mny));
		map<ll, vector<point> > pp;
		for(auto x:xs) {
			for(auto y:ys) {
				pp[chk(x,y)].pb(point(x,y));
				// printf("%lld,%lld  %lld\n", x, y, chk(x,y));
			}
		}
		for(auto i:pp) {
			unordered_map<int, unordered_map<int,int> > ppp;
			int c=0;
			for(auto ix:i.Y) {
				if(ppp[ix.x][ix.y]) continue;
				ppp[ix.x][ix.y] = 1;
				// ix.print();
				c++;
			}
			printf("%d\n",c );
			break;
		}
		// printf("\n");
	}
}