#include <stdio.h>

int f91(int n){
  if(n>=101) return n-10;
  else if(n<=100) return f91(f91(n+11));
}

int main(){
  int x;
  while(1){
    scanf("%d", &x);
    if(x==0) return 0;
    printf("f91(%d) = %d\n", x, f91(x));
  }
}
