#include <stdio.h>
char board[10][11];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<9; i++){
			scanf(" %s", board[i]);
			//for(long long int ix=0, iy=10; ix<9, iy<=10000000000; ix++,iy*=10) board[i][ix] = n%iy - ;
		}
		for(int i=0; i<9;){
			for(int ix=i/3; ix<9; ix+=3, i++) board[i][ix] = board[i][(i/3==2)?ix-1:ix+1];
		}
		//printf("%c", board[0][0]);
		for(int i=0; i<9; i++){
			for(int ix=0; ix<9; ix++) printf("%c", board[i][ix]);
			printf("\n");
		}
	}
}