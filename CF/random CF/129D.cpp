#include <iostream>
#include <stdio.h>
using namespace std;

int check(int n, int x){
  return (n==x) ? 1 : 0;
}

int add_to(int tree[][3], int x, int add){
  int temp[3] = {tree[x][0],tree[x][1],tree[x][2]};
  for(int i=0; i<3; i++){
    tree[x][(i+add)%3] = temp[i];
    //printf("set %d in tree[%d][%d] \n", temp[i], x, (i+add)%3);
  }
}

void print(int tree[][3], int n){
  for(int x=0; x<3; x++){
    for (int i=0; i<n*2; i++){
      cout << tree[i][x] << " ";
      if(i==n-1) cout << "    ";
    }
    cout << endl;
  }
}

void printlazy(int lazy[], int n){
  for (int i=0; i<n*2; i++){
    cout << lazy[i] << " ";
    if(i==n-1) cout << "    ";
  }
  cout << endl;
}

void update_lazy(int tree[][3], int lazy[], int si, int n){
  add_to(tree, si, lazy[si]);
  if(si*2<n){
    lazy[si*2] += lazy[si];
    lazy[si*2+1] += lazy[si];
    lazy[si] = 0;   
  }else{
    tree[si*2][0] = (tree[si*2][0] + lazy[si])%3;
    tree[si*2+1][0] = (tree[si*2+1][0] + lazy[si])%3;
    lazy[si] = 0;
  }
}

void update(int tree[][3], int lazy[], int n, int si, int ss, int se, int rs, int re, int add, bool nolazy=false){
  //cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " lazy[si] " << lazy[si] << endl;
  if(ss > se || rs > se || re < ss) return;
  if(ss==se){
    tree[si][0] = (tree[si][0] + add)%3;
    return;
  }
  if(lazy[si] && !nolazy) update_lazy(tree, lazy, si, n);
  if(ss>=rs && se<=re && si*2<n && !nolazy){
    add_to(tree, si, add);
    if(si*2<n){
      lazy[si*2] = (lazy[si*2] + add)%3;
      lazy[si*2+1] += (lazy[si*2+1] + add)%3; 
    }else{
      tree[si*2][0] = (tree[si*2][0] + add)%3;
      tree[si*2+1][0] = (tree[si*2+1][0] + add)%3;
    } 
    return;
  }

  int mid = (ss+se)/2;
  update(tree, lazy, n, si*2, ss, mid, rs, re, add, nolazy);
  update(tree, lazy, n, si*2+1, mid+1, se, rs, re, add, nolazy);

  if(si*2>=n){ 
    for(int i=0; i<3; i++){
      tree[si][i] = check(tree[si*2][0], i) + check(tree[si*2+1][0], i);
      //cout << "si*2>n " << tree[si][0] << endl;
    }
  }else if(si*2<n){
    tree[si][0] = tree[si*2][0] + tree[si*2+1][0];
    tree[si][1] = tree[si*2][1] + tree[si*2+1][1];
    tree[si][2] = tree[si*2][2] + tree[si*2+1][2];
  }
}

int query(int tree[][3], int lazy[], int n, int si, int ss, int se, int rs, int re){
  //cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << "lazy[si] " << lazy[si] << endl;
  //printlazy(lazy, n);
  if(ss>re || se<rs || ss>se) return 0;
  if(ss==se) return check(tree[si][0], 0);
  if(lazy[si]){
    add_to(tree, si, lazy[si]);
    update_lazy(tree, lazy, si, n);
  }
  if(ss>=rs && se<=re) return tree[si][0];
  int mid = (ss+se)/2;
  return query(tree, lazy, n, si*2, ss, mid, rs, re) + query(tree, lazy, n, si*2+1, mid+1, se, rs, re);
}

int main(){
  int n, q;
  cin >> n >> q;
  int lazy[2*n+1] = {0};
  int tree[2*n+1][3] = {0};
  update(tree, lazy, n, 1, 1, n, 1, n, 0, true);
  for(int i=0; i<q; i++){
    int c,a,b;
    cin >> c >> a >> b;
    if(c==0) update(tree, lazy, n, 1, 1, n, a+1, b+1, 1);
    else if(c==1) cout << query(tree, lazy, n, 1, 1, n, a+1, b+1) << endl;
    
    //print(tree, n);
    //printlazy(lazy, n);
  }
}