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


void dectobinary(int n) {
	bitset<10> x(n);
	cout << x << endl;
}


int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	// scanf("%d", &t);
	vector<int> occ(32), focc(32);
	int sum, lim;
	scanf("%d %d", &sum, &lim);
	for(int i=1; i<=lim; i++) {
		// dectobinary(i);
		occ[__builtin_ctz(i)]++;
	};

	// debug(occ);
	for(int i=31; i>=0; i--) {
		while(occ[i] && sum-(1<<i)>=0) {
			sum -= (1<<i);
			occ[i]--;
			focc[i]++;
		}
	} 
	if(sum) printf("-1\n");
	else {
		vector<int> ans;
		for(int i=1; i<=lim; i++) {
			t = __builtin_ctz(i);
			if(focc[t]) {
				ans.push_back(i);
				focc[t]--;
			}
		};
		printf("%d\n", (int)ans.size());
		for(auto i:ans) {
			printf("%d ", i);
		}
		printf("\n");
	}
	// debug(sum);
	// debug(focc);
}