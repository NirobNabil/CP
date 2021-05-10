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

int hash_t(string s, int n) {
    int hash = 0;
    for(int i=0; i<s.size(); i++) {
        hash += 1 + pow(3,i) * (s[i] - 'a'+1);
    } 
    return hash % 6;
}

int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    scanf("%d", &t);
    vector<int> table(pow(t,t), -1);
    // cerr << table.size() << endl;
    for(int ix=0; ix<5; ix++) {
        string s;
        int v;
        cin >> s >> v;
        printf("Step %d: \n", ix+1);
        printf("load factor is now %f\n", (ix+1)/6.0);
        printf("Inserting (%s, %d):\n", s.c_str(), v);
        printf("Hash\t= ( ");
        for(int i=0; i<s.size(); i++) {
            printf("1 + 3^%d * %d %c", i, s[i], "+)"[i==s.size()-1]);
        }
        int hash = hash_t(s, t);
        printf(" mod %d\n \t\t = %d\n", 6, hash);
        int retry = 1;
        while(table[hash] != -1) {
            // if(s == "the") {
            //     printf("replace hashtable\n");
            // }
            printf("hashtable[%d] is preoccupied and key is not equal to %s so we move on to %d + %d*%d\n", hash, s.c_str(), hash, retry, retry);
            hash += pow(retry, 2);
            hash %= 6;
            retry++;
        }
        table[hash] = v;
        printf("hashtable[%d] is empty so we insert {%s, %d} into hashtable[%d]\n\n", hash, s.c_str(), v, hash);
        // cerr << hash << " " << v << "\n";
    } 
}