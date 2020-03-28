#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string x;
    x+= string(n,'U');
    x+= string(m,'L');
    for(int i=1;i<=n;i++){
        if(i>1) x +="D";
        if(i%2) x+=string(m-1,'R');
        else x+=string(m-1,'L');
    }
 
    cout<<x.length()<<endl<<x;
}