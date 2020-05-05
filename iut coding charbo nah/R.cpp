#include <iostream>
#include <vector>
#include <cmath>
//#include "../../utils/utils.cpp"

using namespace std;

int check(int num){
  return (num == 0) ? 1 : 0;
}

void update(int* st, int n, int ss,int se,int rs,int re,int si,int add){
  cout << " ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << endl;

  //check if queryrange inside segment
  if(ss>se || rs>se || re<ss) return;

  //check if leaf node
  if(ss == se){
    switch(add%3){
    case 1:
      st[si] += add%3;
      break;
    case 2:
      st[si] += add%3;
      break;
    }
    st[si] = st[si]%3;
    return;
  }

  int mid = floor((ss+se)/2);
  update(st, n, ss, mid, rs, re, si*2+1, add);
  update(st, n, mid+1, se, rs, re, si*2+2, add);


  //check if next node is not a leaf node
  if(si*2 < n) st[si] =st[si*2+1] + st[si*2+2];
  else if(si*2+1 > n) st[si] = check(st[si*2+1]) + check(st[si*2+2]);

}

int query(int* st,int ss,int se,int rs,int re,int si){
  if(ss>se || rs<ss || re>se) return 0;
  else if(ss>=rs && se<=re) return st[si];
  else{
    int mid = (ss+se)/2;
    return  query(st, ss, mid, rs, re, si*2+1) + query(st, mid+1, se, rs, re, si*2+2);
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  int lazy[2*n] = {0};
  int tree[2*n] = {0};
  for(int i=0; i<q; i++){
    int c, a, b;
    cin >> c >> a >> b;
    if(c == 0){
      update(tree,n, 0, n-1, a, b, 0, 1);
      //printArray(tree, n);
    }else if(c == 1){
      cout << query(tree, 0, n-1, a, b, 0) << endl;
    }
    for (int i=0; i<n; i++) cout << tree[i] << " ";
    cout << endl;
    for(int i=n; i<n*2; i++) cout << tree[i] << " ";
    cout << endl;
  }
}
