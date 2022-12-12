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

struct node {
    // char c;
    node* next[27];
    bool has_end;
    node() {
        for( int i=0; i<27; i++ ) next[i] = NULL;
        has_end = false;
    }
} default_node;

node* root = new node();

void insert( string s ) {
    node* curr = root;
    int i = 0, n = s.length();
    while( i < n ) {
        int si = s[i] - 'a';
        if( curr->next[si] == NULL ) 
           curr->next[si] = new node();
       curr = curr->next[si];
       i++;
    }
    curr->has_end = true;
}

bool search( string s ) {
    node* curr = root;
    int i = 0, n = s.length();
    while( i < n ) {
        int si = s[i] - 'a';
        if( curr->next[si] == NULL ) 
            return false;
        curr = curr->next[si];
        i++;
    }
    if( curr->has_end ) return true;
    else return false;
}





int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        insert( s ); 
    }
    string s;
    cin >> s;
    cout << search(s) << endl;
}


