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
#define S1 1009


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
#define bs bitset<10>

bs c(1);
unordered_map<bs, bool> pos;
int i, ix, t, n, m, k, p, q, gg, x, y, z;
vector<int> a(S1);

bool chk(bs b, int l, ll sum) {
	// debug(l,sum);
	// cout << b << endl;
	if(pos[b]) return pos[b];
	if(sum > x) return 0;
	if(l==3) {
		if(sum == x) {
			for(int i=0; i<n; i++) {
				if(b[i] == 1) printf("%d ", i+1);
			}
			return 1;
		}else return 0;
	}
	bool p = 0;
	for(int i=0; i<n; i++) {
		if(b[i]) continue;
		p |= chk(b | (c << i), l+1, sum+a[i]);
		// debug(p);
		if(p) break;
		// debug("no broke");
	}
	pos[b] = p;
	return p;
}

int main(){
	// scanf("%d", &t);
	t = 1;
	while(t--){
		scanf("%d %d", &n, &x);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }
    // debug(a);
    if(chk(bs(0), 0, 0) == 0) {
    	printf("IMPOSSIBLE\n");
    }
	}
}