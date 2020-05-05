#include <iostream>
#include <vector>
#include <cmath>
<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> a7ccd52cf94edb78f3039650085ed045146f24dd
//#include "../../utils/utils.cpp"

using namespace std;

<<<<<<< HEAD
int check(int num, int equalto){
  return (num == equalto) ? 1 : 0;
}

void addd(int st[][3], int i, int add){
  int temp[3] = {st[i][0], st[i][1], st[i][2]};
  for(int x=0; x<3; x++){
    int n = temp[x];
    int nextX = (x + add)%3;
    printf("setting st[%d][%d] = %d \n", i, nextX, n);
    st[i][nextX] = n;
  }
}

void update(int st[][3], int* lazy, int n, int ss,int se,int rs,int re,int si,int add, int nolazy=false){
  cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " " << lazy[1] << endl;
  //check if queryrange inside segment
  if(ss>se || rs>se || re<ss) return;

  
  if(lazy[si] != 0){
    addd(st, si, lazy[si]);
    if(si*2 < n){
      //printf("setting lazy[%d] += %d", si, lazy[si*2] + lazy[si] + add);
      lazy[si*2] += lazy[si] + add;
      lazy[si*2+1] += lazy[si] + add;
      lazy[si] = 0;
    }else{
      //printf("setting st[%d] += %d", si, (st[si*2][0] + lazy[si] + add)%3 );
      st[si*2][0] = (st[si*2][0] + lazy[si] + add)%3;
      st[si*2+1][0] += (st[si*2+1][0] + lazy[si] + add)%3;
      lazy[si] = 0;
      return;
    }
  }

  //check if leaf node
  if(ss>=rs && se<=re){
    if(ss == se){
    switch(add%3){
      case 1:
        st[si][0] += add%3;
      case 2:
        st[si][0] += add%3;
        break;
      }
      st[si][0] = st[si][0]%3;
      printf("set st[%d][0] = %d \n", si, st[si][0]%3);
      return;
    }
    else if(!nolazy){
      addd(st, si, lazy[si] + add);
      if(si*2 < n){
        cout << "Setting lazy[" << si*2 << "] = " << lazy[si] + add << endl;
        lazy[si*2] += lazy[si] + add;
        lazy[si*2+1] += lazy[si] + add;
      }else{
        cout << "Setting st[" << si*2 << "] = " << (st[si*2][0] + lazy[si] + add)%3 << endl;
        st[si*2][0] = (st[si*2][0] + lazy[si] + add)%3;
        st[si*2+1][0] += (st[si*2+1][0] + lazy[si] + add)%3;
      }
      lazy[si] = 0;
      return;
    }
  }

  int mid = floor((ss+se)/2);
  update(st, lazy, n, ss, mid, rs, re, si*2, add, nolazy);
  update(st, lazy, n, mid+1, se, rs, re, si*2+1, add, nolazy);


  //check if next node is not a leaf node
  if(si*2 < n){
    st[si][0] =st[si*2][0] + st[si*2+1][0];
    st[si][1] =st[si*2][1] + st[si*2+1][1];
    st[si][2] =st[si*2][2] + st[si*2+1][2];
    cout << "setting " << si << "= si*2 + si*2+1 = " << st[si*2][0] + st[si*2+1][0] << endl;
  }
  else if(si*2 >= n){
    st[si][0] = check(st[si*2][0],0) + check(st[si*2+1][0],0);
    st[si][1] = check(st[si*2][0],1) + check(st[si*2+1][0],1);
    st[si][2] = check(st[si*2][0],2) + check(st[si*2+1][0],2);
    cout << "setting " << si << "= check(si*2) + check(si*2+1) = " << check(st[si*2][0],0) + check(st[si*2+1][0],0) <<  endl;
  }

}

int query(int st[][3], int *lazy, int n, int ss,int se,int rs,int re,int si){
  cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << endl;

  if(ss>se || re<ss || rs>se) return 0;

  if(lazy[si] != 0){
    cout << "lazy aint zero" << endl;
    addd(st, si, lazy[si]);
    if(si*2 < n){
      printf("setting lazy[%d] += %d", si*2, lazy[si]);
      lazy[si*2] += lazy[si];
      lazy[si*2+1] += lazy[si];
    }else{
      printf("setting st[%d] += %d", si*2, st[si*2][0] + lazy[si]);
      st[si*2][0] = (st[si*2][0] + lazy[si])%3;
      st[si*2+1][0] = (st[si*2][0] + lazy[si])%3;
    }
    lazy[si] = 0;
  }

  if(ss>=rs && se<=re){
    cout << "in range" << endl;
    if(ss == se) return check(st[si][0],0);
    else return st[si][0];
  }
  else{
    cout << "not fully in range" << endl;
    int mid = floor((ss+se)/2);
    return  query(st, lazy, n, ss, mid, rs, re, si*2) + query(st, lazy, n, mid+1, se, rs, re, si*2+1);
=======
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
>>>>>>> a7ccd52cf94edb78f3039650085ed045146f24dd
  }
}

int main(){
  int n, q;
  cin >> n >> q;
<<<<<<< HEAD
  int lazy[2*n+1] = {0};
  int tree[2*n+1][3] = {0};
  //building the tree
  update(tree, lazy, n, 1, n, 1, n, 1, 0, true);
=======
  int lazy[2*n] = {0};
  int tree[2*n] = {0};
>>>>>>> a7ccd52cf94edb78f3039650085ed045146f24dd
  for(int i=0; i<q; i++){
    int c, a, b;
    cin >> c >> a >> b;
    if(c == 0){
<<<<<<< HEAD
      update(tree, lazy, n, 1, n, a+1, b+1, 1, 1);
      //printArray(tree, n);
    }else if(c == 1){
      cout << query(tree, lazy, n, 1, n, a+1, b+1, 1) << endl;
    }


    for (int i=0; i<n*2; i++){
      cout << tree[i][0] << " ";
      if(i==n-1) cout << "    ";
    }
    cout << endl;
    for (int i=0; i<n*2; i++){
      cout << tree[i][1] << " ";
      if(i==n-1) cout << "    ";
    }
    cout << endl;
    for (int i=0; i<n*2; i++){
      cout << tree[i][2] << " ";
      if(i==n-1) cout << "    ";
    }
    cout << endl;

    for (int i=0; i<n*2; i++){
      cout << lazy[i] << " ";
      if(i==n-1) cout << "    ";
    }
=======
      update(tree,n, 0, n-1, a, b, 0, 1);
      //printArray(tree, n);
    }else if(c == 1){
      cout << query(tree, 0, n-1, a, b, 0) << endl;
    }
    for (int i=0; i<n; i++) cout << tree[i] << " ";
    cout << endl;
    for(int i=n; i<n*2; i++) cout << tree[i] << " ";
>>>>>>> a7ccd52cf94edb78f3039650085ed045146f24dd
    cout << endl;
  }
}
