#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  int gg=0;
  for(;gg<t; gg++){
    int d[4], b[4];
    scanf("%d.%d.%d.%d", &d[0], &d[1], &d[2], &d[3]);
    scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);
    int i=0,ix=0, i1=0, mismatch=0;
    for(i1=0; i1<4; i1++){
      int temp=0;
      for(i=10,ix=1;i<=100000000; i*=10, ix*=2) temp += (b[i1]%i)/(i/10) * ix;
      if(temp != d[i1]) mismatch = 1;
    }
    if(mismatch>0) printf("Case %d: No\n", gg+1);
    else printf("Case %d: Yes\n", gg+1);
  }
}
