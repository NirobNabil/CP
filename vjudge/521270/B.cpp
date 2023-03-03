
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
    cin >> t;
        cin.ignore();
        cin.ignore();
    while(t--){
        map<char,int> pr;
        pr['+'] = pr['-'] = 1;
        pr['*'] = pr['/'] = 2;

        string s;
        vector<char> st, op;
        while( getline(cin, s) && s.size() != 0 ) {
            char x = s[0];
            if( x < '0' ) {
                if( x == ')' ) {
                    while( op.back() != '(' ) {
                        st.push_back(op.back());
                        op.pop_back();
                    }
                    op.pop_back();
                } else {
                    while( op.size() && x != '(' && op.back() != ')' && op.back() != '(' && pr[op.back()] >= pr[x] ) {
                        st.push_back(op.back());
                        op.pop_back();
                    }
                    op.push_back(x);
                }
                
            } else st.push_back(x);
        }

        while(op.size()) st.push_back(op.back()), op.pop_back();

        for( auto x : st ) cout << x; 
        cout << "\n";
        if( t!=0 ) cout << "\n";
    }
}

