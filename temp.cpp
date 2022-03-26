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

#define MAXN 1000
class Stack {
    public:
        int st[MAXN];
        int tp = -1;

        void push( int x ) {
            st[++tp] = x;
        }

        void pop() {
            tp = max(-1, tp-1);
        }   

        int top() {
            if( tp==-1 ) return -1;
            return st[tp];
        }

        int size() {
            return tp+1;
        }
} pegA, pegB, pegC; 

Stack pegs[3] = [&pegA, &pegB, &pegC];

void init( int n ) {
    for(int i=n; i>0; i++) {
        pegA.push(i);
    }
}

void print() {
    int as = pegA.size(), bs = pegB.size(), cs = pegC.size();
    for(int i=max({as,bs,cs}); i>0; i--) {
        if( i < as ) printf("%d ", &pegA.st[i]);
        else printf("  ");

        if( i < bs ) printf("%d ", &pegB.st[i]);
        else printf("  ");

        if( i < cs ) printf("%d ", &(pegC.st[i]));
        else printf("  ");
    } 
}

void move_disk( char a, char b ) {
    int x = a-'A', y = b - 'A';
    if( pegs[x].top() > pegs[y].top() && pegs[y].top() == -1 ) {
        printf("Illegal Move\n");
        return;
    }
    pegs[y].push(pegs[x].top());
    pegs[x].pop();
}

int main(){
    init(5);
    move_disk('A', 'B');
}