#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<vector<ll> > grid(100);
vector<pair<ll,ll> > vi;
vector<pair<ll,ll> > vv;
vector<ll > vm;

ll chk(ll i, bool d) {
    if(d ? i==vv.size()-1 : i==0) return vm[i];
    ll nxt = d ? chk(i+1,d) : chk(i-1,d);
    if(vm[i] > vv[i].X+nxt) {
        vm[i] = vv[i].X+nxt;
    }
    return vm[i];
}

ll dfs()

int main(){
    ll i, ix, t, n, a[S1];
    scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        for(int ix=0; ix<n; ix++) {
            scanf("%lld,", &t);
            grid[ix].push_back(t);
        } 
    }

    // for(int i=0; i<n; i++) {
    //  for(int ix=0; ix<n; ix++) {
    //      printf("%lld ", grid[ix][i]);
    //  } 
    //  printf("\n");
    // }
    // printf("\n");
    


    // printf("\n");
    for(int i=0; i<n; i++) {
        for(int ix=0; ix<n; ix++) {
            printf("%lld ", grid[ix][i]);
        } 
        printf("\n");
    }
    printf("%lld\n", grid[0][0]);
}