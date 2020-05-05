#include<bits/stdc++.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    int i,j;
    cin>>j;
    while(j--){
      float time=0;
      float n,a,b,c,d,time1,time2,m;
      cin>>n>>m;
      for(int i=0;i<n;i++){
        scanf("%f: %f %f: %f",&a,&b,&c,&d);
        time1 = (c-a);
        time2 = (d-b);
        time+=time1+time2/60;
      }
      if(time>=m){
          cout<<"YES"<<endl;
      }
      else{
          cout<<"NO"<<endl;
      }
    }

}
