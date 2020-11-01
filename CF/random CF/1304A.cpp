#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  // while(t--){
  //   long double n, g, b;
  //   cin >> n >> g >> b;
  //   long double x = (n/(2*g));
  //   long double y = (n-(x*g))/b;
  //   long long int xfloor = floor(x);
  //   long long int yfloor = floor(y);
  //   long double resdouble = 0;
  //   long long int res = 0;
  //   if(xfloor%2 == 0) res = (xfloor)*(g+b) + (x-xfloor)*g + (y-yfloor)*b;
  //   else if(xfloor%2 == 1) res = (xfloor-1 + y)*(g+b) + xfloor*g + (x-xfloor)*g + (y-yfloor)*b;
  //   cout << x << ", " << y << "  " << ceil(res) << endl;
  // }
  while(t--){
    long double n, g, b;
    cin >> n >> g >> b;
    long double x = (n/(2*g));
    long double y = (n-(x*g))/b;
    long long int xceil = ceil(x);
    long long int yfloor = floor(y);
    long double resdouble = 0;
    long long int res = 0;
    if(xceil*g > n) res = n;
    else if(xceil%2 == 1) res = (g+b)*xceil - b;
    else if(xceil%2 == 0) res = (g+b)*xceil;
    // if(xceil%2 == 0) res = (g+b)*xceil - xceil*g;
    // else if(xceil%2 == 1) res = (xfloor-1 + y)*(g+b) + xfloor*g + (x-xfloor)*g + (y-yfloor)*b;
    cout << x << ", " << y << "  " << xceil << ", " << yfloor << "  " << res << endl;
  }
}