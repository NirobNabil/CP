#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int _check(int x, int m){
  if((x%m)-(m/10-1) == 7 || (x%m)-(m/10-1) == 4) return 1;
  else return 0;
}

int check(int x){
  if(_check(x,10) && _check(x,100) && _check(x,1000) && _check(x,10000)) return 1;
  else return 0;
}

void print(int tree[], int n){
  for (int i=0; i<n*2; i++){
    cout << tree[i] << " ";
    if(i==n-1) cout << "    ";
  }
  cout << endl;
}

int _pow(int x, int n){
  return (int)pow(x,n);
}

void update(int tree[], int n, int si, int ss, int se, int rs, int re, int add, bool build=false){
  cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << endl;
  if(ss > se || rs > se || re < ss) return;
  if(ss==se){
    tree[si] += add;
    return;
  }
  // if(ss>=rs && se<=re && !build){
  //   lazy[si] += add;
  // }
  // if(lazy[si] && !build){
  //     lazy[si*2] += lazy[si];
  //     lazy[si*2+1] += lazy[si];
  //     lazy[si] = 0;
  // }

  int mid = (ss+se)/2;
  update(tree, n, si*2, ss, mid, rs, re, add, build);
  update(tree, n, si*2+1, mid+1, se, rs, re, add, build);
  
  if(si*2>=n) tree[si] = check(tree[si*2]) + check(tree[si*2+1]);
  else tree[si] = tree[si*2] + tree[si*2+1];
}

int query(int tree[], int n, int si, int ss, int se, int rs, int re){
  if(ss>re || se<rs || ss>se) return 0;
  if(ss==se) return check(tree[si]);
  if(ss>=rs && se<=re) return tree[si];
  int mid = (ss+se)/2;
  return query(tree, n, si*2, ss, mid, rs, re) + query(tree, n, si*2+1, mid+1, se, rs, re);
}


int main(){
  int n, m;
  cin >> n >> m;
  int tree[n*2+1] = {0};
  for(int i=n; i<n*2; i++) cin >> tree[i];
  update(tree, n, 1, 1, n, 1, n, 0, true);
  print(tree, n);
  for(int i=0; i<m; i++){
    string c;
    int l,r,d;
    cin >> c >> l >> r;
    if(c=="add"){
      cin >> d;
      update(tree, n, 1, 1, n, l, r, d);
    }else if(c=="count") cout << query(tree, n, 1, 1, n, l, r) << endl;
    print(tree, n);
    //printlazy(lazy, n);
  }
}