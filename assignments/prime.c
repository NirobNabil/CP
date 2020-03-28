#include <stdio.h>
#include <math.h>
#define N 10000

//assuming num wont be greater than 10000
int main(){
  int num=0;
  scanf("%d", &num);
  int x[N]={0}, gg=0;
  for(int i=2; i<(int)ceil(sqrt(num));){
    if(num%i == 0){
      x[gg] = i;
      gg++;
      num=num/i;
      i=2;
    }else i++;
  }
  x[gg] = num;
  for(int i=0; x[i]!=0; i++) printf("%d ", x[i]);
}
