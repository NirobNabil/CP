#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    printf("%d", (x>y) ? x*b : y*a);
  }
}