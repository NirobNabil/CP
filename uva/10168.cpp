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
#define max 10000000

vector<int> primes;
char nums[max+1] = {0};
void generate_primes(){
    int i=3, ix;
    for(; i<=max; i+=2){
        ix=i+i;
        if(!nums[i]) for(; ix<=max; ix+=i) nums[ix] = 1; 
    }
    primes.push_back(2);
    i=3;
    for(; i<=max; i+=2){
        if(!nums[i]) primes.push_back(i);
    }
}



int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	generate_primes();
	while(scanf("%d", &n) != EOF){
		if(n%2==0 && n>=8) {
			printf("2 2 ");
			n -= 4;
		}else if(n%2==1 && n>=9) {
			printf("3 2 ");
			n -= 5;
		}else {
			printf("Impossible.\n");
			continue;
		}
		for(auto i:primes) {
			if(binary_search(primes.A(), primes.B(), n-i)) {
				printf("%d %d\n", i, n-i);
				break;
			}
		}
	}
}