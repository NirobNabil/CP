#include <iostream> 
#include <cmath>
#include <string>

using namespace std;

int main(){
  int n;
  cin >> n;
  string x;
  if(n%2 == 1){
    x = "7";
  }else{
    x = "1";
  }
  n /= 2;
  n--;
  while(n--) x += "1";
  cout << x << endl;
}