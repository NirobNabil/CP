#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, d, m=0, x=-1;
    cin >> n >> d;
    while(n--){
      int gg;
      cin >> gg;
      if(d == gg) x = 1;
      m = max(m, gg);
    }
    if(d/m == 1 && d%m == 0) x = d/m;
    x = (x==-1) ? ( (d/m != 0) ? ( (d%m == 0)? d/m : d/m +1 ): 2) : x;
    cout << x << endl;
  }
}