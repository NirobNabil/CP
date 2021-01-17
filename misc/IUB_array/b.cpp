#include <iostream>
using namespace std;

int r,c;
int occ[100]={0};

char getMaxChar(char (*grid)[1000]) {
    for(int i=0; i<r; i++) {
        for(int ix=0; ix<c; ix++) {
            occ[grid[i][ix]-'a']++;
        } 
    }
    int mx=0;
    char mi=-1;
    for(int i=0; i<100; i++) {
        if(mx<occ[i]) mx=occ[i], mi = i;
    }
    return mi+'a'; 
}


int main(){
    cout << "Row size: ";
    cin >> r;
    cout << "Col size: ";
    cin >> c;
    char a[r][1000];
    cout << "Enter the elements:\n";
    for(int i=0; i<r; i++) {
        for(int ix=0; ix<c; ix++) {
            cin >> a[i][ix];
        }
    }
    char mxchar = getMaxChar(a);
    for(int i=0; i<100; i++) {
        if(occ[i]==occ[mxchar-'a']) 
            cout << "\"" << (char)(i+'a') << "\" appears " << occ[i] << " times\n";
    } 
}