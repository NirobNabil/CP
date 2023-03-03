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


vector<int> parent(S1), r(S1);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    r[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
}

int main(){
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
    string s;
    char c;
    // getline(cin, s);
	while(t--){
        int corr=0, incorr=0;
		scanf("%d", &n);
        parent.resize(n+9);
        for(int i=0; i<=n; i++) parent[i] = i; 
        r.resize(n);
        for(int i=0; i<=n; i++) r[i] = 0; 
        // cout << n << t << "gg" << endl;
	    getline(cin, s);
        while(getline(cin, s)) {
            if(s == "") break;
            sscanf(s.c_str(), "%c %d %d", &c, &x, &y);
            if(c=='c') {
                union_sets(x,y);
                // debug(parent);
            }else {
                // debug(x,y,find_set(x), find_set(y));
                if(find_set(x) == find_set(y)) corr++;
                else incorr++;
            }
        }
        cout << corr << "," << incorr << "\n" << (t!=0 ? "\n" : "") ;            
	}
}