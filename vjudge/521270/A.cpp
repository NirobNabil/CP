
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
    ix = 0;
    while(++ix <= t){
        scanf("%d", &n);
        vector<int> a(n);
        vector<pp> s;
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        
        vector<int> rects(n);
        s.push_back({0,-1});
        for( int i=0; i<n; i++ ) {
            if( a[i] > s.back().X ) {
                s.push_back({a[i], i});
            } else {
                int prev = rects[i];
                while( a[i] <= s.back().X ) {
                    rects[i] = abs(i - s.back().Y);
                    if( s.back().Y != -1 ) 
                        rects[i] += rects[s.back().Y];
                    s.pop_back();
                }
                rects[i] += prev;
                s.push_back({a[i], i});
            } 
            //debug(s);
            //debug(rects);
        }
        //debug("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGg");
        s.clear();
        s.push_back({0,-1});
        vector<int> rectd(n);
        for( int i=n-1; i>=0; i--) {
            if( a[i] > s.back().X ) {
                s.push_back({a[i], i});
            } else {
                int prev = rectd[i];
                while( a[i] <= s.back().X ) {
                    rectd[i] = abs(i - s.back().Y);
                    if( s.back().Y != -1 ) 
                        rectd[i] += rectd[s.back().Y];
                    s.pop_back();
                }
                rectd[i] += prev;
                s.push_back({a[i], i});
            } 
            //debug(s);
            //debug(rectd);
        }

        for(int i=0; i<n; i++) {
            rects[i] += rectd[i] + 1;
            rects[i] *= a[i];
        }

        printf("Case %d: %d\n", ix, *max_element(rects.A(), rects.B()));

        //printf("Case %d: %d\n", ix, mx);
    }
}

