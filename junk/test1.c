#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int min(int a, int b, bool op){
  return (a>b) ? (op? a : b) : (op? b : a);
}

int lexicographic_sort(const char* a, const char* b) {
  for(int i=0; i<min(strlen(a), strlen(b), false); i++){
    if((int)a[i] == (int)b[i]) continue;
    else if((int)a[i] > (int)b[i]) return 0;
    else if((int)a[i] < (int)b[i]) return 1;
  }
  return 1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
  char* uniqa[strlen(a)];
  char* uniqb[strlen(b)];
  for(int i1=0; i1<strlen(a); i1++){
    for(int i2=0; i2<strlen(uniqa); i2++){
      printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
      if(a[i1] == uniqa[i2]) continue;
    }
    size_t len = strlen(uniqa);
    uniqa[len++] = a[i1];
    uniqa[len] = '\0';
  }
  for(int i1=0; i1<strlen(b); i1++){
    for(int i2=0; i2<strlen(uniqb); i2++){
      if(b[i1] == uniqb[i2]) continue;   
    }
    size_t len = strlen(uniqb);
    uniqb[len++] = b[i1];
    uniqb[len] = '\0';
  }
  return (strlen(uniqa) != strlen(uniqb)) ? ((strlen(uniqa) > strlen(uniqb)) ? 0 : 1) : !lexicographic_sort(a,b);
}

int main(){
  char* a = "tttttttttttttttttttttttttter";
  char* b = "wewe";
  printf("%d", sort_by_number_of_distinct_characters(a, b));
}