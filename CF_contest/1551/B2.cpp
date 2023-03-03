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


int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		string s;
		scanf("%d %d", &n, &k);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int c = 0;
		map<int, int> f;
		map<int, vector<int> > ci;
		for(int i=0; i<n; i++) {
			f[a[i]]++;
		} 
		vector<pp> cv;
		for(auto i:f) {
			cv.push_back({i.Y, i.X});
		}
		// sort(cv.A(), cv.B(), greater<pp>());
		// debug(cv);
		vector<pp> hahalol;
		for(int i=0; i<cv.size(); i++)  {
			int x = cv[i].Y;
			int y = 0;
			while(f[x]-y && y<k) {
				y++;
				hahalol.push_back({x,++c});
				// ci[x].pb(c++);
				debug(c,x);
				if(c==k) {
					c=0;
				}
			}
			
		} 
		debug(hahalol);
		while(c!=0) {
			hahalol.pop_back();
			c--;
		}
		for(auto i:hahalol) {
			ci[i.X].push_back(i.Y);
		}
		for(int i=0; i<n; i++) {
			if(ci[a[i]].size()) {
				printf("%d ", ci[a[i]].back());
				ci[a[i]].pop_back();
			}else printf("0 ");
		}
		printf("\n");
	}
}