#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a>b)?b:a)

int coo[2001][2] = {0};

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int next=0, max=0, min=2001, temp, res=0;
        memset(coo, 0, sizeof(coo));
        for(int i=0; i<n; i++){
            scanf("%d %d", &coo[i], &coo[i][1]);
        }
        for(int i=0, r=0, g=0; i<n-2; i++){
            for(int ix=0; ix<n; ix++){
                if(!g) if(coo[ix][0]==coo[ix][1]) 
            }
        }
        printf("res %d\n", res);
    }
}