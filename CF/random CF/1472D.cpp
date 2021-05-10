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
		multiset<int, greater<int> > e, o;
		for(int i=0; i<n; i++) {
    	scanf("%d", &x);
    	if(x%2) o.in(x);
    	else e.in(x);
    }
    bool t = 1;
    if(n == 2) {
    	if(e.empty()) printf("Bob\n");
    	else if(o.empty()) printf("Alice\n");
    	else if(*o.A() > *e.A()) printf("Tie\n");
    	else printf("Alice\n");
    	continue;
    }
    std::vector<ll> s(2,0);
    while(!e.empty() || !o.empty()) {
    	if(e.empty()) {
    		s[t] += *o.A() - (t?*o.A():0); 
    		// printf("1\n");
    		o.erase(o.A());
    	}
    	else if(o.empty()) {
    		// printf("2\n");
    		s[t] += *e.A() - (t?0:*e.A());
    		e.erase(e.A());
    	}
    	else {
    		if(*e.A() > *o.A()) {
    		// printf("3\n");
    			s[t] += *e.A() - (t?0:*e.A());
    			e.erase(e.A());
    		}else { 
    		// printf("4\n");
    			s[t] += *o.A() - (t?*o.A():0);
    			o.erase(o.A());
    		}
    	}
    	t = !t;
    	// debug(s);
    }
    printf("%s\n", s[0]>s[1]?"Bob":s[0]==s[1]?"Tie":"Alice");
    // printf("%d %d\n", s[0], s[1]);
	}
}

/*
1
8
1
9
1
5
1
7
1
3
1
4
1
1
1
6
1
2
1
10
2
7 8
2
7 9
2
7 7
2
7 6
2
7 5
2
7 10
2
1 5
2
7 1
2
7 4
2
7 3
2
7 2
2
1 4
2
6 10
2
6 9
2
6 8
2
6 7
2
6 6
2
1 6
*/