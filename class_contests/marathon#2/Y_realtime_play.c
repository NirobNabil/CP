#include <stdio.h>

int main(){
	char grid[3][3], winner='N';
	int x=0,z=0,illegal=0,i,ix;
	for(i=0; i<3; i++) scanf("%c %c %c\n", &grid[i][0], &grid[i][1], &grid[i][2]);
	for(i=0; i<3; i++) for(ix=0; ix<3; ix++) if(grid[i][ix]=='X') x++; else if(grid[i][ix]=='0') z++;
	for(i=0; i<3; i++) if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){ if(winner != 'N' && winner != grid[i][0] && grid[i][0] != '.') illegal=1; if(grid[i][0]!='.') winner = grid[i][0]; }
	for(i=0; i<3; i++) if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){ if(winner != 'N' && winner != grid[0][i] && grid[0][i] != '.') illegal=1; if(grid[0][i]!='.') winner = grid[0][i]; }
	if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){ if(winner != 'N' && winner != grid[0][0] && grid[0][0] != '.') illegal=1; if(grid[0][0]!='.') winner = grid[0][0]; }
	if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){ if(winner != 'N' && winner != grid[2][0] && grid[2][0] != '.') illegal=1; if(grid[2][0]!='.') winner = grid[2][0]; }
	if(x-z>1 || x-z<-1 || z>x || illegal || (winner=='0' && z<x) || (winner == 'X' && z>=x)) printf("illegal\n");
	else if(winner!='N' && winner!='.') printf("the %s player won\n", (winner=='X')?"first\0":"second\0");
	else if(x+z==9) printf("draw\n"); 
	else printf("%s\n", (x-z==1)?"second\0":"first\0");
	return 0;
}