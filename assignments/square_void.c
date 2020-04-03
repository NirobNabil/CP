#include <stdio.h>
#include <string.h>

int main(){
  int len, ix;
  scanf("%d", &len);
  len = len*2;
  for(int i=0; i<len; i++){
    printf("*");
  }
  printf("\n");
  for(int ix=1; ix<len-1; ix++){
    printf("*");
    for(int i=1; i<len-1; i++){
      printf(" ");
    }
    printf("*\n"); 
  }
  for(int i=0; i<len; i++){
    printf("*");
  }
}