#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char board[8][8];
int done = 1, k = 0;
int dfs(char grid[8][8], int x, int y){
	if(grid[x][y] == '.'){
		return 0;
	}else if(k==0){
		done =0;
		return 0;
	}
	grid[x][y] = '.';
	k--;
	return ((x==7 && done)? 0 : dfs(grid, x+1, y))  
			 + ((y==7 && done)? 0 : dfs(grid, x, y+1))  
			 + ((x==0 && done)? 0 : dfs(grid, x-1, y))  
			 + ((y==0 && done)? 0 : dfs(grid, x, y-1)) 
			 + ((x==7 && y==7 && done)? 0 : dfs(grid, x+1, y+1)) 
			 + ((x==0 && y==0 && done)? 0 : dfs(grid, x-1, y-1)) 
			 + ((x==7 && y==0 && done)? 0 : dfs(grid, x+1, y-1))
			 + ((x==0 && y==7 && done)? 0 : dfs(grid, x-1, y+1))
			 + 1; 
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		k = 0, done=1;
		for(int i=0; i<8; i++) {
			for(int ix=0; ix<8; ix++){
				board[ix][i] = 'X';
			} 
		}
		scanf("%d", &k);
		dfs(board, 0, 0);
		board[0][0] = 'O';
		for(int i=0; i<8; i++) {
			for(int ix=0; ix<8; ix++){
				printf("%c", board[ix][i]);
			} 
			printf("\n");
		}
		printf("\n");
	}
}