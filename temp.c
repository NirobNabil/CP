#include <stdio.h>
#include <string.h>

//int sum[10] = {0,1,3,6,10,15,21,28,36,45}
char gg[1000000000];

/*
730
832
491
504
295
402
420
*/
int main(){
    // int t;
    // scanf("%d", &t);
    // for(int ix=1; ix<=t; ix++){
    //  int a, b;
    //  scanf("%d %d", &a, &b);
    //  a += a%3;
    //  printf("%d\n", (b-a)/3);
    // }
    int sum=0;
    scanf("%s", gg);
    for(int i=0; i<strlen(gg); i++){
        sum += gg[i];
        // printf("%d %d %d %d\n", i, divis[i], sum, ((sum%3==0)?1:0));
        //divis[i+1] = divis[i] + ((sum%3==0)?1:0);
        //sums[i+1] = sum;
    }
    printf("%d\n", sum);
    // int n;
    // scanf("%d", &n);
    // int s=0;
    // if(sum>9) s += sum[9];
    // n -= 9;
    // sum += sum[n/10-1]*10 + (n%10+1)*(n/10);
    // sum += sum[n/100-1]*10 + (n%100+1)*(n/100);
    // n = n%10;
}