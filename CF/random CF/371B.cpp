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

#define MAX(a,b) ((a>b)?a:b)
#define max 46341

map<int,int> primes;
void prime_factors(map<int,int> &occurences, int n)
{
    while (n % 2 == 0)
    {
		primes[2] = 1;
    	occurences[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
        	primes[i] = 1;
            occurences[i]++;
            n = n/i;
        }
    }
 
    if (n > 2) {
    	primes[n] = 1;
        occurences[n]++;
    }
}

int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z, a, b;
	scanf("%d %d", &a, &b);
	map<int,int> ag, bg;
	prime_factors(ag, a);
	prime_factors(bg, b);
	int pos = 1, ans = 0;
	for(auto p:primes) {
		if(p.X==2 || p.X==3 || p.X==5) {
			ans += abs(ag[p.X] - bg[p.X]);
			continue;
		} 
		if(ag[p.X] != bg[p.X]) {
			pos = 0; break;
		}
	} 
	debug(primes);
	if(pos != 1) printf("-1\n");
	else printf("%d\n", ans);
}