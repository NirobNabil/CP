#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


vector<string> grid;
map<int, map<int,int> > mp;

// axis = 1 -> x axis

// int getgrid(int x, int y, int axis) {
// 	if(axis) return grid[y][x];
// 	else return grid[x][y];
// }

// void traverse(int q, int i, bool r, int end, int axis, vector<int>& list) {
// 	for(int i=0; ix<x; ix++)
// 		for(int i=0; ix<x; ix++)
// 			list[i] = min(list[i], list[i-1]);
// }

void ppp(){
	for(auto i:mp) {
		for(auto ix:i.Y) cout << ix.Y << " ";
		cout << "\n";
	}
}


void chk(int x, int y) {

	for(int ix=0; ix<x; ix++) {
		mp[0][ix] = min( (grid[0][ix]=='1' ? 0 : 400) , mp[0][ix]);
		for(int iy=1; iy < y; iy++) {
			if(grid[iy][ix]=='1') mp[iy][ix] = 0;
			else mp[iy][ix] = min(mp[iy][ix], mp[iy-1][ix]+1);
		}
	}
	// debug(grid[0][0]);
	for(int ix=0; ix<x; ix++) {
		mp[y-1][ix] = min( (grid[y-1][ix]=='1' ? 0 : 400) , mp[y-1][ix]);
		for(int iy=y-2; iy >= 0; iy--) {
			if(grid[iy][ix]=='1') mp[iy][ix] = 0;
			else mp[iy][ix] = min(mp[iy][ix], mp[iy+1][ix]+1);
		}
	}

	for(int iy=0; iy<y; iy++)
		for(int ix=1; ix < x; ix++) 
			mp[iy][ix] = min(mp[iy][ix], mp[iy][ix-1]+1);


	for(int iy=y-1; iy>=0; iy--)
		for(int ix=x-2; ix >= 0; ix--) 
			mp[iy][ix] = min(mp[iy][ix], mp[iy][ix+1]+1);

}z

int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &y, &x);
		grid.clear();
		mp.clear();
		grid.resize(y);
		for(int i=0; i<y; i++) {
			cin >> grid[i];
		}
		for(int ix=0; ix<x; ix++) 
			for(int iy=0; iy<y; iy++)
				mp[iy][ix] = 400;  
		chk(x,y);
		ppp();
		// debug(grid);
		// debug(mp[0][0]);
	}
}