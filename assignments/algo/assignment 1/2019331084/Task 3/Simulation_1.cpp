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


map<int, map<int,bool> > vis;
int f[] = {1,-1,0};
const int sx = 1000, sy = 1000;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(34);
	int t = 1000, n, m, k, p, q, gg, z, pos;
	
	int nx, ny;
	ll total = 0;

	while(t--) {
		int x = sx, y = sy;
		vis.clear();
		int step = 1000;
		while(step) {
			vis[x][y] = true;
			int pos = 0; 
			for(int i=0; i<9; i++) {
				nx = x + f[i/3];
				ny = y + f[i%3];
				if( !(nx!=x ^ ny!=y) ) continue;
				else if( !vis[nx][ny] ) {
					pos = 1;
					break;
				}
			} 
			if( !pos ) break;
			nx = x + f[rand()%3];
			ny = y + f[rand()%3];
			if( vis[nx][ny] || !(nx!=x ^ ny!=y)  ) continue;
			x = nx,  y = ny;
			step--;
		}
		total += abs( sx - x ) + abs( sy - y );
	}


	cout << total / 1000.0 << "\n";
}