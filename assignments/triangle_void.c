#include <stdio.h>
#include <string.h>

int main(){
  int len;
  scanf("%d", &len);
  len = len*2;
  for(int i=len/2; i > 0; i--){
    int ix=0;
    //printf("%d\n", i);
    if(i==1){
      printf(" ");
      for(; ix<len-1; ix++){
        printf("*");
      }
    }else{
      for(; ix<i; ix++) printf(" ");
      if(len-i - ix >= 2){
        printf("*");
        for(++ix; ix<len-i; ix++){
          printf(" ");
        }
        printf("*");  
      }else{
        for(; ix<=len-i; ix++){
          printf("*");
        }
      }
      for(; ix<=len; ix++) printf(" ");
        printf("\n", len);
      }
    }
}