    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using pii = pair<int, int>;
     
    int ask(int l, int r) {
        cout << "? " << l << " " << r << endl;
        int x;
        cin >> x;
        return x;
    }
     
    int searchL(int l, int r) {
        int x = r;
        int lo = l, hi = r-1;
     
        while(lo <= hi) {
            int mid = lo + hi >> 1;
        		printf("x - %d\n", x);
            int y = ask(mid, x);
     		
            if(y == x) lo = mid + 1;
            else hi = mid - 1;
        } return hi;
    }
     
    int searchR(int l, int r) {
        int x = l;
        int lo = l+1, hi = r;
     
        while(lo < hi) {
            int mid = lo + hi >> 1;
            int y = ask(x, mid);
     
            if(y == x) hi = mid - 1;
            else lo = mid + 1;
        } return lo;
    }
     
    void solve() {
        ll n;
        cin >> n;
     
        int x = ask(1, n), ans;
        bool f;
        if(x == 1) f = 1;
        else if(x == n) f = 0;
        else f = (ask(1, x) != x);
     
        if(!f) ans = searchL(1, x);
        else ans = searchR(x, n);
     
        cout << "! " << ans << endl;
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        int t = 1;
        // cin >> t;
     
        while(t--) solve();
        
        return 0;
    }                                       