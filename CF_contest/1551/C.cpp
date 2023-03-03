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

#define bigpp pair<string, unordered_map<char,int> >

int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	int fq = 0;
	while(t-- && ++fq){
		scanf("%d", &n);
		vector<pair<string, unordered_map<char,int> > > a;
		unordered_map<char,int> gx;
		int ts = 0;
		for(int i=0; i<n; i++) {
			string s;
			cin >> s;
			unordered_map<char, int> x;
			for(int i=0; i<s.length(); i++) {
				x[s[i]]++;
				gx[s[i]]++;
			} 
			ts += s.length();
			a.push_back({s, x});
	    }

	    int mx = 0;
	    for(char c='a'; c<'f'; c++) {
	    	sort(a.A(), a.B(), [&](bigpp &a, bigpp &b){
	    		// if((-a.X.length()+a.Y[c]*2) == (-b.X.length()+b.Y[c]*2)) {
	    		// 	return a.Y[c] < b.Y[c];
	    		// }else 
	    		return (int)(a.Y[c]*2 - a.X.length()) < (int)(b.Y[c]*2 - b.X.length());
	    	});
	    	int len = ts, cx = gx[c], i = 0;
	    	// debug(c,cx,len);
	    	// for(auto i:a) {
	    	// 	debug(i.X, i.Y);
	    	// }
	    	while(cx <= (len-cx) && i<n) {
	    		cx -= a[i].Y[c];
	    		len -= a[i].X.length();
	    		i++;
		    	// debug(cx,len,i);
	    	}

	    	if(cx > len-cx) {
	    		// debug(i);
	    		mx = max(n-i, mx);
	    	}
	    } 
	    
	    printf("%d\n", mx);
	}
}