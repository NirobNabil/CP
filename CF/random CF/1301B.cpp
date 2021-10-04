#include <iostream> 
#include <set>
#include <cmath>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int arr[n];
    set <int> fs;
    for(int i=0; i<n; i++) cin >> arr[i];
    //for(int i=0; i<n; i++) cout << arr[i] << " ";
    //cout << endl;
    int f=-1, l=-1;
    for(int i=0; i<n; i++){
      if(arr[i] == -1 && arr[i-1] != -1 && i != 0) fs.insert(arr[i-1]);
      if(arr[i+1] != -1 && arr[i] == -1 && i+1 < n) fs.insert(arr[i+1]);
    }
    if(fs.size() == 0) fs.insert(0);
    //cout << *fs.begin() << " " << *(--fs.end()) << " " << fs.size() << endl;
    int max = 0, ans = floor( (*fs.begin() + *(--fs.end()))/2 );
    for(int i=0; i<n-1; i++){
      int f = (arr[i] == -1) ? ans : arr[i], l = (arr[i+1] == -1) ? ans : arr[i+1];
      //cout << f << " " << l << endl;
      max = (abs(l-f) > max) ? abs(l-f) : max;
    }
    cout << max << " " << ans << endl;
  }
}