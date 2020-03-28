#include<stdio.h>

int main() {
  int c1, c2, r1, r2;
  scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
  int matA[c1][r1], matB[c2][r2], res[r1][c2];
  for(int i=0; i<r1; i++) for(int ix=0; ix<c1; ix++) scanf("%d", &matA[i][ix]);
  for(int i=0; i<r1; i++) for(int ix=0; ix<c2; ix++) scanf("%d", &matB[i][ix]);  
  //for(int i=0; i<r1; i++) for(int ix=0; ix<c1; ix++) printf("%d%s", matB[i][ix], (ix+1==c1)?"\n":"\t");
  if(c1 != r2) printf("not possible\n");
  else{
    for(int i=0; i<r1; i++){
      for(int ix=0; ix<c2; ix++){
        int sum=0; 
        //printf("( ");
        for(int iy=0; iy<r2; iy++){
          sum += matA[i][iy] * matB[iy][ix];
          //printf("%d*%d(%d) + ", matA[i][iy], matB[iy][ix], sum);
        }
        //printf(") ");
        res[ix][i] = sum;
      }
      //printf("\n");
    }
  }
  for(int i=0; i<r1; i++) for(int ix=0; ix<c2; ix++) printf("%d%s", res[ix][i], (ix+1==c2)?"\n":"\t");
}