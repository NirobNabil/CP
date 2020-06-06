Ushan replied to you

    kono O(1) type soln ache?


Yea
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define PB push_back
#define MP make_pair
#define TS to_string
#define F first
#define S second
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d,e,f,i,j,k,m,n,o,x1,y1,x2,y2,s1=0,s2=0,s=0;
        cin>>x1>>y1>>x2>>y2;
        a=x2-x1;
        b=y2-y1;
        if(b>=a){
            s=a*(a+1)/2+a*(b-a)+a*(a-1)/2;
        }
        else{
            s=b*(b+1)/2+b*(b-1)/2+(a-b)*b;
        }
        cout<<s+1<<"\n";
    }
}