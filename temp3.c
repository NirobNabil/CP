#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
    int n=10;
    // unsigned int d[n];
    // memset(d, 0b11111111, sizeof(d));
    unordered_map<int, unordered_map<int,int>> d, t;
    // fill(d, d+n, t);
    for(int i=0; i<10; i++) {
        cout << d[i].size() << endl;
        // d[i][3] = 5;
        if(d[i][5]) printf("gg\n");
    }
    // printf("%u\n", 0b11111111111111111111111111111111+);
}