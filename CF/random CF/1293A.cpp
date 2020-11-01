#include <bits/stdc++.h>
using namespace std;

//m=1 -> MAX
int check(int a, int b, bool m){return (a>b)? (m)? a : b : (m)? b : a; }  

int main(){
  int t, n, s, k;
  cin >> t;
  while(t--){
    cin >> n >> s >> k;
    int closed[k] = {999999};
    unordered_set <int> closed_s;
    int floors[n+1] = {0};
    // for(int i=0; i<n; i++) cout << floors[s] << " ";
    // cout << endl;
    for(int i=0; i<k; i++){
      int x;
      cin >> x;
      closed[i] = x;
      closed_s.insert(x);
      floors[x] = 1;
    }
    // int d=(k==0)?0 : 99999;
    // for(int i=0; i<k; i++){
    //   if(closed[i]+1 <= n && !closed_s.count(closed[i]+1)){
    //     //cout << ( (closed[i]+1<s)? s-(closed[i]+1): (closed[i]+1)-s ) << "  <-first  ";
    //     d = check(d, (closed[i]+1<s)? s-(closed[i]+1): (closed[i]+1)-s, 0);
    //   }
    //   if(closed[i]-1 >= 1 && !closed_s.count(closed[i]-1)){
    //     //cout << ( (closed[i]-1<s)? s-(closed[i]-1): (closed[i]-1)-s ) << "  <-second  ";
    //     d = check(d, (closed[i]-1<s)? s-(closed[i]-1): (closed[i]-1)-s, 0);
    //   }
    //   //cout << d << endl;
    // }
    int d=999999999, d2=999999999;
    for(int i=1; i<=n; i++){
      if(!floors[i]){
        d = check(d, (i>s)?i-s:s-i, 0);
      }
    }
    cout << d << endl;
  }
}