#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ll;

ll check(ll s,ll n,ll ip,ll im,vector<bool> rs){
  //cout << "ip = " << ip << "im = " << im << endl;
  if(rs[ip]==1 && rs[im]==1) return check(s, n, ip+( (ip<n)?1:0 ), im-( (im>1)?1:0 ), rs);
  else if(rs[ip]==0 || rs[im]==0){
    return (rs[ip]==0) ? ip-s : s - im;
  }
}

int main(){
  int t;
  cin >> t;
  int res[t];
  while(t--){
    ll n, s, k;
    cin >> n >> s >> k;
    vector<bool>rs(n+1,false);
    //bool rs[1000000000] = {false};
    for(int i=0; i<k; i++){
      ll x; cin >> x;
      rs[x] = true;
    }
    cout << check(s,n,s,s,rs) << endl;
  }
  return 0;
}
