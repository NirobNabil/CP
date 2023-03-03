
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

string a, b;
int dp[1001][1001];


int chk( int x, int y ) {
    if( x >= a.size() || y >= b.size() ) return 0;
    if( dp[x][y] ) return dp[x][y];

    if( a[x] == b[y] ) {
        return dp[x][y] = 1 + chk( x+1, y+1 );
    }

    return dp[x][y] += max( chk(x+1, y), chk(x, y+1) );

}

int main(){
    int i, ix, t, n, m, k, p, q, gg, x, y, z;
    
    while( cin >> a >> b ){
        //debug(a,b);
        memset(dp, 0, sizeof(dp));
        //cout << chk( 0,0 ) << "\n"; 
       

        for( int x=a.size()-1; x>=0; x-- ) {
            for( int y=b.size()-1; y>=0; y-- ) {
            //cerr << x << ", " << y << endl;
                if( a[x] == b[y] ) {
                    dp[x][y] = 1 + dp[x+1][y+1];
                } else {
                    dp[x][y] = max( dp[x+1][y], dp[x][y+1] );
                }
            }
        }

        cout << dp[0][0] << "\n";

    }
}

