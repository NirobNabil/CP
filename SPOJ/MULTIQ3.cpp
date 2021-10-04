#include <bits/stdc++.h>
#define vii int
#define vi int
using namespace std;

const int sz = 200009;
vi lazy[sz];
vii tree[sz][3];

int add_to(int x, int add){
  int temp[3] = {tree[x][0],tree[x][1],tree[x][2]};
  for(int i=0; i<3; i++){
    tree[x][(i+add)%3] = temp[i];
  }
}

void update_lazy( int si, int ss, int mid){
  lazy[si+1] = (lazy[si+1] + lazy[si])%3;
  lazy[si+2*(mid-ss+1)] = (lazy[si+2*(mid-ss+1)] + lazy[si])%3;   

  add_to(si+1, lazy[si]);
  add_to(si+2*(mid-ss+1), lazy[si]);

  lazy[si] = 0;
}

void update_tree( int si, int ss, int mid) {
  for(int i=0; i<3; i++) 
    tree[si][i] = tree[si+1][i] + tree[si + 2*(mid-ss+1)][i];
}


void build( int si, int ss, int se) {
  // if(ss > se || rs > se || re < ss) return;
  //cout << "s-1 " << endl;
  if(ss==se){
    tree[si][0] = 1;
    return;
  }

  int mid = (ss+se)/2;
  build(si+1, ss, mid);
  build(si+2*(mid-ss+1), mid+1, se);

  update_tree(si, ss, mid);
}


void update( int si, int ss, int se, int rs, int re, int add){
  // cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " l " << lazy[si] << endl;
  if(ss > se || rs > se || re < ss) return;
  //cout << "s-1 " << endl;
  if(ss==se){
    add_to(si, add);
    // cout << "v: " << tree[si][0] << " " << tree[si][1] << " " << tree[si][2] << " " << endl;
    return;
  }

  int mid = (ss+se)/2;
  if(lazy[si]) 
    update_lazy(si, ss, mid);

  if(ss>=rs && se<=re){
    lazy[si] += add;
    add_to(si, add);
    // cout << "v: " << tree[si][0] << " " << tree[si][1] << " " << tree[si][2] << " " << endl;
    return;
  }

  // cout << "v: " << tree[si][0] << " " << tree[si][1] << " " << tree[si][2] << " " << endl;

  update(si+1, ss, mid, rs, re, add);
  update(si+2*(mid-ss+1), mid+1, se, rs, re, add);

  update_tree(si, ss, mid);

}

int query(int si, int ss, int se, int rs, int re){
  // cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << "l " << lazy[si] << endl;
  if(ss>re || se<rs || ss>se) return 0;
  // cout << "v: " << tree[si][0] << " " << tree[si][1] << " " << tree[si][2] << " " << endl;
  if(ss==se) return tree[si][0];

  int mid = (ss+se)/2;
  if(lazy[si]){
    update_lazy(si, ss, mid);
  }
  if(ss>=rs && se<=re) return tree[si][0];

  return (
    query(si + 1, ss, mid, rs, re) 
    + query(si + 2*(mid-ss+1), mid+1, se, rs, re)
  );
}

int solve() {
  int n, q;
  cin >> n >> q;
  // vi lazy(3*n+1, 0);
  // vii tree(3*n+1, vector<char>(3, 0));
  // vector<char> vx(3, 0);
  memset( tree , 0, sizeof ( tree ) );
  memset( lazy , 0, sizeof( lazy ) );
  build(1, 1, n);
  for(int i=0; i<q; i++){
    int c,a,b;
    cin >> c >> a >> b;
    if(c==0) update(1, 1, n, a+1, b+1, 1);
    else if(c==1) cout << query(1, 1, n, a+1, b+1) << endl;
    //print(tree, n);
    //printlazy(lazy, n);
  }
}

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++) {
    cout << "Case " << i << ":\n";
    solve();
  }   
}

// Case 1:
// 2
// 3
// 0
// 2