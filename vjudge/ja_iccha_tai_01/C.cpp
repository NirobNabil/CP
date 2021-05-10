#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define endl '\n'
 
void solve() {
    int n, x;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
 
    for(int i=1; i<=n; i++) {
        int x = v[i-1];
        int y = sqrt(x);
        if((y+1) * (y+1) == x) y++;
        if(y * y != x) {cout << "YES" << endl; return;}
    }
 
    cout << "NO" << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
 
    while(t--) solve();
    
    return 0;
}