#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

int main(){
  int t=0,n=0;
  cin >> t;
  //cout << "gededed";
  vector<tuple<int,int,int>> res;
  bool first=0, second=0;
  while(t--){
    cin >> n;
    second = false;
    first = false;
    //cout << "gg";
    for(int i=2; i<= static_cast<int>(sqrt(n)) && !first; i++){
      if(n%i == 0){
        //cout << "came 2 ";
        int x = n/i;
        for(int j=2; j<= static_cast<int>(sqrt(x)) && !second; j++){
          if(x%j == 0){
            //cout << "came 2 ";
            if(i!=j && i!=x/j && j != x/j){
              cout << "YES" << endl;
              cout << i << " " << j << " " << x/j << endl;
              second = true;
              first = true;
            }
            //res.push_back(make_tuple(i,j,x/j));
          }
        }
      }
    }
    if(!second && !first) cout << "NO" << endl;
  }
  //for(int i=0; i<res.size(); i++) cout << get<0>(res[i]) << ", " << get<1>(res[i]) << ", " << get<2>(res[i]) << endl;
}