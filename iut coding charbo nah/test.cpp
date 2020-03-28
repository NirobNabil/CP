#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll lcm(ll a, ll b) {
     return a / __gcd(a, b) * b;
}

int main(){
     int n, x;
     cin >> n;

     vector<ll> v;
     while(n--) cin >> x, v.push_back(x);

     //sort(v.rbegin(), v.rend());
     //ll mx = *v.begin(),
     ll ans = 0;

     for(ll x : v){
       for(ll y : v){
         ans = max(ans, lcm(x,y));
       }
     }

     cout << ans << endl;
}
