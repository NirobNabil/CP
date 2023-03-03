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
		scanf("%d", &n);
		vector<vector<int> > a(5, vector<int>(n));
		vector<vector<pp> > b(5, vector<pp>(n));
		// vector<vector<pair<int,int> > > b(5, vector<pp>(n));
		for(int i=0; i<n; i++) {
			for(int ix=0; ix<5; ix++) {
				// debug(ix,i);
				scanf("%d", &a[ix][i]);
				b[ix][i] = make_pair(a[ix][i], i);
			} 
	    }

	 //    for(int i=0; i<5; i++) sort(b[i].A(), b[i].B());
	 //    unordered_map<int,int> q;
		// for(int i=0; i<n; i++) q[i] = INT_MAX;
		// for(int i=0; i<n; i++) {
		// 	for(int ix=0; ix<5; ix++) {
		// 		q[b[ix][i].Y] = min(q[b[ix][i].Y], i);
		// 	} 
		// }
		// debug(q);
	    vector<int> g;
	    for(int i=0; i<n; i++) g.pb(i);
	    // sort(g.A(), g.B(), [&](int &a, int &b) {
	    // 	return q[a] < q[b];
	    // });
		// debug(g);

	    // debug(b[0]);
	    vector<int> fm(n, 3);
	    int p = 0;
		for(auto i:g) {
			// int mn = INT_MAX;
			// for(int ix=0; ix<5; ix++) {
			// 	// if(a[i][ix] < a[i][mn]) mn = ix;
			// 	x = lower_bound(b[ix].A(), b[ix].B(), a[ix][i]) - b[ix].A();
			// 	mn = min(mn, x);
			// }
			// debug(mn);
			// // if(a[i][mn] > 2) continue;
			// if(mn > 5) continue;
			// debug(i);
			// vector<int> f = fm;
			// debug(f);
				if(fm[i]<0) continue;
			int c = n-1;
			for(int x=0; x<n; x++) {
				if(x==i) continue;
				for(int ix=0; ix<5; ix++) {
					fm[x] -= (a[ix][x] > a[ix][i]);
				}
				if(fm[x] <= 0) c--;
				else continue;
			}
			if(c == 0) {
				p = 1;
				printf("%d\n", i+1);
				break;
			}
		}	
		if(p==0) printf("-1\n");
		// debug(mx);
	}
}