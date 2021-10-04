#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    int num[n+2];
    int mins[n+1][( int )ceil(log2(n))+2];
    for(int i=1; i<=n; i++){
        scanf("%d", &num[i]);
        mins[i][0] = num[i];
    }
    //num[n] = INT_MAX;
    int log = ( int )log2(n)+1;
    for(int ix=1; ix<=log; ix++){
        for(int i=1; i<=n; i++){
            mins[i][ix] = max(mins[i][ix-1], mins[min(n, i+( int )pow(2,ix) -( int )pow(2,ix-1))][ix-1]);                       
        }
    }
    while(q--){
        int a,b,d,r=INT_MAX;
        // scanf("%d %d", &a, &b);
        scanf("%d", &d);
        for(a=1; a<=n-d+1; a++) {
            b = a+d-1;
            int max_p = ( int )log2(b-a+1);
            // cout << a << " " << b << endl;
            r = min( r, max(mins[a][max_p], mins[b-(int)pow(2,max_p)+1][max_p]) );
        }
        printf("%d\n", r);
    }
}