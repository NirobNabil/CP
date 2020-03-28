#include <stdio.h>

int main(){
	char grid[3][3], winner='N';
	int x=0,z=0;
	for(int i=0; i<3; i++) scanf("%c %c %c\n", &grid[i][0], &grid[i][1], &grid[i][2]);
	for(int i=0; i<3; i++) for(int ix=0; ix<3; ix++) if(grid[i][ix]=='X') x++; else if(grid[i][ix]=='0') z++;
	for(int i=0; i<3; i++) if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) winner = grid[i][0];
	for(int i=0; i<3; i++) if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) winner = grid[0][i];
	if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) winner = grid[0][0];
	if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) winner = grid[2][0];
	if(x-z>1 || x-z<-1) printf("Illegal\n");
	else if(winner!='N' && winner!='.') printf("%s player won\n", (winner=='X')?"first\0":"second\0");
	else if(x-z!=0) printf("%s\n", (x-z==1)?"Second\0":"First\0");
	else printf("%s\n", (x+z==9)?"draw\0":"First\0");
	printf("%d %d %c\n", x,z, winner);
	return 0;
}