#include <stdio.h>
#include <math.h>

int getprime(int n){
    int i=1, c=0, x;
    bool gg;
    if(n==2) return 3;
    if(n==1) return 2;
    while(i++) {
        gg=false;
        x = (int)sqrt(i);
        for(int ix=2; ix<=x; ix++) {
            if(i%ix==0) {
                gg=true;
                break;
            }
        }
        if(gg==false) c++;
        if(c==n) return i;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", getprime(n));
}