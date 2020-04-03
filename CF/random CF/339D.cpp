#include <iostream>
#include <cmath>
using namespace std;

int check(int n, int x){
  int i=0;
  for(; x<n; x*=2, i++){}
  return (i%2==0) ? 1 : 0;
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

void update(int tree[], int n, int si, int ss, int se, int rs, int re, int new_num, bool build=false){
  cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " new_num " << new_num << endl;
  if(ss > se || rs > se || re < ss) return;
  if(ss==se){
    if(!build) tree[si]= new_num;
    return;
  }

  int mid = (ss+se)/2;
  update(tree, n, si*2, ss, mid, rs, re, new_num, build);
  update(tree, n, si*2+1, mid+1, se, rs, re, new_num, build);
  
  if(check(n, si)) tree[si] = tree[si*2] ^ tree[si*2+1];
  else tree[si] = tree[si*2] | tree[si*2+1];
}


int main(){
  int n, m;
  cin >> n >> m;
  n = (int)pow(2,n);
  int tree[n*2+1] = {0};
  for(int i=n; i<n*2; i++) cin >> tree[i];
  update(tree, n, 1, 1, n, 1, n, 0, true);
  print(tree, n);
  for(int i=0; i<m; i++){
    int p,b;
    cin >> p >> b;
    update(tree, n, 1, 1, n, p, p, b);
    cout << tree[1] << endl;
    print(tree, n);
    //printlazy(lazy, n);
  }
}