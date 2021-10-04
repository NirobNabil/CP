#include <stdio.h>
#include <math.h>
#include <string.h>
#define max(a, b) (a>b)?a:b

void string_assign(char* gg, char* names, int index){
  for(int i=0; i<=strlen(gg); i++){ //using <= for taking into account the \0 char
    names[i+index] = gg[i];
  }
}

int main(){
  int n=3, prices[n], total=0;
  scanf("%d", &n);
  char names[n*51]; //extra for \0
  for(int i=0; i<n; i++){
    int price=0;
    char name[51];
    scanf("%s %d", name, &price);
    prices[i]=price;
    string_assign(name, names, i*51);
  }
  printf("SL no. %-51s   price\n", "name  ");
  printf("______ %-51s  %-3s\n", "____ ", "______");
  int i=0;
  for(; i<n; i++){
    char name[51];
    int tempI=0;
    while(names[tempI+i*51] != NULL){
      name[tempI] = names[tempI+i*51];
      tempI++;
    }
    name[tempI] = '\0';
    total += prices[i];
    printf("%03d    ", i+1);
    printf("%-51s  ", name);
    printf("%6d\n", prices[i]);
  }
  printf("__________________________________________________________________\n");
  printf("%03d   %51s%9d\n", i, "", total);
  printf("_____  %51s    ____\n", "");
  printf("%s%51s       %s", "total", "", "sum");
}
