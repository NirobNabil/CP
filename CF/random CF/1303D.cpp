#include <bits/stdc++.h>

using namespace std;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int check(int *arr, bool *bools, int i, int n){
  if(arr[i]<=n) n -= arr[i];
  boolsx[i] = 1;
  for(int i=0; i<n; i++) check(arr, bools, ++i. n);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n ,m;
    cin >> n >> m;
    int boxes[m];
    for(int i=0; i<m; i++){
      cin >> boxes[i];
    }
    qsort(boxes, m, sizeof(int), cmp);
    for(int i=0; i<m; i++) cout << boxes[i] << " ";
    cout << endl;
    for(int i=0; n!=0; i++){
      if(n<boxes[i]) 
    }
  }
}