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
	int i, ix, t, n, m, k, p, gg, x, y, z;
	int log[S1+1];
	log[1] = 0;
	for (int i = 2; i <= S1; i++)
	    log[i] = log[i/2] + 1;

	while(scanf("%d", &n) && n!=0) {
		scanf("%d", &k);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
	    	scanf("%d", &a[i]);
	    }
	    vector<int> f = {1};
	    vector<int> s = {1};
	    for(int i=1; i<n; i++) {
	    	if(a[i] != a[i-1]) {
	    		s.pb(i+1);
	    		f.push_back(0);
	    	}
	    	f.back()++;
	    } 
	    f.pb(0);
	    s.pb(n+1);

	    vector<vector<int> > st(S1, vector<int>(50,0));
	    for (int i = 0; i < f.size(); i++)
	    	st[i][0] = f[i];

		for (int j = 1; j <= log[f.size()]; j++) {
		    for (int i = 0; i + (1 << j) <= f.size(); i++) {
		        st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
		    }
		}

		for(int i=0; i<k; i++) {
			scanf("%d %d", &x, &y);
			int sx = upper_bound(s.A(), s.B(), x) - s.A();
			int sy = --upper_bound(s.A(), s.B(), y) - s.A();
			int fq = 1;
			int j;
			if(sx < sy) {
				sy--;
				j = log[sy - sx + 1];
				fq = max(max(s[sx]-x, y-s[sy+1]+1), max(st[sx][j], st[sy - (1 << j) + 1][j]));
			} else if(sx == sy) fq = max(s[sx]-x, y-s[sy]+1);
			else fq = y - x +1;
			printf("%d\n", fq);
		} 


	    debug(f);
	}

}