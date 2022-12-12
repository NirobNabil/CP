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

typedef vector<ll> vi;


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



vi tree(S1*4, 0), lazy(S1*4, 0);

void print(vi &tree, int si, int n){
    map<int, vi > out;
    for( int i=0, si=0; i<= ceil(log2(n)); i++ ) {
      while( si < pow(2, i) ) {
        cout << si << "-" << tree[si++] << " ";
      }
      cout << "\n";
    }
}



void build(vi &a, vi &tree, int n, int si, int ss, int se){
  //cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " lazy[si] " << lazy[si] << endl;
  if(ss==se){
    if( ss <= n ) tree[si] += a[ss];
    else tree[si] = 0;

    // cout << "itree[" << si << "] = " << tree[si] << endl;
    return;
  }

  int mid = (ss+se)/2;
  build(a, tree, n, si*2, ss, mid);
  build(a, tree, n, si*2+1, mid+1, se);

  tree[si] = tree[si*2] + tree[si*2+1];
  // cout << "tree[" << si << "] = " << tree[si] << endl;
}

void update(vi &a, vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re, ll add){
  // cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << endl;
  if(ss > se || rs > se || re < ss) return;
  if(ss==se){
    tree[si] += add;
    a[ss] += add;
    return;
  }

  // si*2 > n if si is a leaf node
  if(ss>=rs && se<=re && si<n){
    lazy[si] += add*(se-ss+1);
    tree[si] += add*(se-ss+1);
    return;
  }

  if(lazy[si]){
    // cout << si << " - " << si*2 << endl;
    lazy[si*2] = lazy[si];
    lazy[si*2+1] = lazy[si];
    tree[si*2] = lazy[si*2];
    tree[si*2+1] = lazy[si*2+1];
    lazy[si] = 0;
    // print( lazy, 1, n*2 );
  }

  int mid = (ss+se)/2;
  update(a, tree, lazy, n, si*2, ss, mid, rs, re, add);
  update(a, tree, lazy, n, si*2+1, mid+1, se, rs, re, add);

  tree[si] = tree[si*2] + tree[si*2+1];
}

int query(vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re){
  //cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << "lazy[si] " << lazy[si] << endl;
  // printlazy(lazy, n);
  if(ss>re || se<rs || ss>se) return 0;
  if(ss==se) return tree[si];
  if(ss>=rs && se<=re) return tree[si];


  // ekhane += hobe na = e thik ache think carefully
  if(lazy[si]){
   tree[si*2] = lazy[si]/2;
   tree[si*2+1] = lazy[si]/2;
   lazy[si] = 0;
  }

  int mid = (ss+se)/2;
  return (
    query(tree, lazy, n, si*2, ss, mid, rs, re) 
    + query(tree, lazy, n, si*2+1, mid+1, se, rs, re)
  );
}



int main(){
  ll t, n, m, k, p, q, gg, x, y, z, pos;
  scanf("%lld", &t);
  vector<ll> a(1, 0);
  for(int tt=1; tt<=t; tt++) {
    fill(tree.A(), tree.B(), 0);
    fill(lazy.A(), lazy.B(), 0);
    // printf("Case %d:\n", tt);
    scanf("%lld %lld", &n, &q);
    a.resize(n+1);
    fill(a.A(), a.B(), 0);

    // build( a, tree, n, 1, 1, n );

    for(int i=0; i<q; i++) {
      ll c;
      scanf("%lld", &c);
      // cout << endl << "new - " << c << endl ;
      if( c == 0 ) {
        scanf("%lld %lld %lld", &x, &y, &z);

        // cout << "print - u" << "\n";
        // print( tree, 1, n*2 );
        // print( lazy, 1, n*2 );
        
        update( a, tree, lazy, n, 1, 1, n, x, y, z );
        
        // cout << "print - u" << "\n";
        // print( tree, 1, n*2 );
        // print( lazy, 1, n*2 );
      }

      if( c == 1 ) {
        scanf("%lld %lld", &x, &y);
        // cout << "print - q" << "\n";
        // print( tree, 1, n*2 );
        printf("%d\n", query( tree, lazy, n, 1, 1, n, x, y ));
        // cout << "print - q" << "\n";
        // print( tree, 1, n*2 );
      }
    }     
  }
}
