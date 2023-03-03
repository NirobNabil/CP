
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


int mx = 50;
vector<int> arr(mx+9);
map<int,vector<int> > ansarr;


void sieve(){
    for(int i=2; i<mx; i++) {
        for(int j=i; j<mx; j+=i) {
            arr[j]++;
        }
    }
    debug(arr);
    ansarr[1] = {1};
    for(int i=2; i<mx; i++) ansarr[arr[i]].push_back(i); 
    for(auto i:ansarr) debug(i.X, i.Y);
}



int main(){
    sieve();
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if( ansarr[n].size() > 0 )
            cout << ansarr[n][0] + 1 << "\n"; 
        else cout << "nai\n";
    }
}

