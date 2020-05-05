#include <stdio.h>
#define ll long long

int main()
{
    ll int a, b;
    while(1){
      scanf("%lld %lld", &a, &b);
      if(a==0 && b==0) return 0;
      int c=0, step=0;
      c=0, step=0;
      while(a>0 || b>0){
          c=((a%10)+(b%10)+c)/10;
          a/=10;
          b/=10;
          step+=c;
      }
      if(step==0)
        printf("No carry operation.\n");
      else{
        printf("%d carry operation", step);
        if(step>1) printf("s.\n");
        else printf(".\n");
      }
    }
    return 0;
}
