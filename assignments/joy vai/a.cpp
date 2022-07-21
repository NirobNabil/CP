#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 100007

using namespace std;

int r[MAX], a[MAX], b[MAX];
int ri = 0;

bool search( int a[], int l, int x ) {
    for( int i=0; i < l; i++ )
        if( a[i] == x ) return true;

    return false;
}

void setunion( int la, int lb ) {
    memset(r, 0, sizeof(r));
    ri = 0;

    for( int i=0; i<la; i++ ) r[ri++] = a[i];

    for( int i=0; i<lb; i++ )
        if( !search(r, ri, b[i]) )
            r[ri++] = b[i];

}

void intersection( int la, int lb ) {
    memset(r, 0, sizeof(r));
    ri = 0;

    for( int i=0; i<la; i++ )
        if( search(b, lb, a[i]) )
            r[ri++] = a[i];
}
    
void difference( int la, int lb ) {
    memset(r, 0, sizeof(r));
    ri = 0;

    for( int i=0; i<la; i++ )
        if( !search(b, lb, a[i]) )
            r[ri++] = a[i];

    for( int i=0; i<lb; i++ )
        if( !search(a, la, b[i]) )
            r[ri++] = b[i];

    
}

int main() {
    string as, bs, o;
    while( cin >> as && as != "X" ) {
        cin >> o >> bs;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int la = 0, lb = 0;

        for( int i=0; i<as.length(); i++ ) a[la++] =  as[i] - '0';
        for( int i=0; i<bs.length(); i++ ) b[lb++] =  bs[i] - '0';;
        
        switch( o[0] ) {
            case 'U':
                setunion( la, lb );
                break;
            case 'I':
                intersection( la, lb );
                break;
            case 'D':
                difference( la, lb );
                break;
        } 

        for( int i=0; i<ri; i++ ) cout << r[i];
        cout << "\n";
    }
}