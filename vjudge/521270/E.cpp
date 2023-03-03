
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
        scanf("%d %d", &n, &m);
        deque<int> q;
        vector<int> wheel(m);
        map<int, set<int> > visited;
        int time = 0;
        for( i=0; i<m; i++ ) {
            wheel[i] = i;
        }
        while( i < n ) {
            q.push_back(i++);
        }

        while( gg < n*m ) {
            int cur = time % m;
            int prev_person = wheel[cur];
            for( auto i:q ) {
                if( visited[i].lower_bound(cur) == visited[i].end() ) {
                    visited[i].insert(cur);
                    wheel[cur] = i;
                    gg++;
                    break;
                }
            }
            q.push_back( prev_person );
            time++;
            debug(q);
            debug(wheel);
        }

        cout << time << endl;
    }
}

