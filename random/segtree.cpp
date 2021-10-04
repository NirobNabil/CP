#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
//#include "../../utils/utils.cpp"

using namespace std;

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

void update(int st[], int n, int ss,int se,int rs,int re,int si,int add){
  //cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " " << lazy[1] << endl;
  //check if queryrange inside segment
  if(ss>se || rs>se || re<ss) return;

  //check if leaf node
	if(ss == se){
    st[si][0] = st[si][0]+=1;
    printf("set st[%d][0] = %d \n", si, st[si][0]%3);
    return;
  }

  int mid = floor((ss+se)/2);
  update(st, lazy, n, ss, mid, rs, re, si*2, add, nolazy);
  update(st, lazy, n, mid+1, se, rs, re, si*2+1, add, nolazy);

  //check if next node is not a leaf node
  st[si] = st[si*2] + st[si*2+1];
}

int query(int st[][3], int n, int ss,int se,int rs,int re,int si){
  cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << endl;

  if(ss>se || re<ss || rs>se) return 0;

  if(ss>=rs && se<=re){
    cout << "in range" << endl;
   	return st[si];
  }
  else{
    cout << "not fully in range" << endl;
    int mid = floor((ss+se)/2);
    return  query(st, n, ss, mid, rs, re, si*2) + query(st, n, mid+1, se, rs, re, si*2+1);
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  //building the tree
  update(tree, lazy, n, 1, n, 1, n, 1, 0);
  for(int i=0; i<q; i++){
    int c, a, b, x;
    cin >> c >> a >> b >> x;
    if(c == 1){
      update(tree, n, 1, n, a+1, b+1, 1, x);
      //printArray(tree, n);
    }else if(c == 2){
      cout << query(tree, n, 1, n, a+1, b+1, 1) << endl;
    }else if(c==3){
    	cout << 
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
    cout << endl;
  }
}
