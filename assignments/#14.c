#include <stdio.h>
#define MAX(a,b) (a>b)?a:b

FILE *input, *output;

int main(){
	input = fopen("./input.txt", "r");
	output = fopen("./output.txt", "w");
	int n,m,max=0;
	fscanf(input, "%d %d", &n, &m);
	char name[n][21];
	int age[n], weight[n], marks[n][m], total[n] = {0}, highest_mark[m] = {0};
	for(int i=0; i<n; i++){
		fscanf(input, "%[^0-9]s", name[i]);
		fscanf(input, "%d %d", &age[i], &weight[i]);
		for(int ix=0; ix<m; ix++){
			fscanf(input, "%d", &marks[i][ix]); 
			total[i] += marks[i][ix]; 
			highest_mark[ix] = MAX(highest_mark[ix], marks[i][ix]);
		}
		max = MAX(max, total[i]);
		fprintf(output, "%s %d %d %d ", name[i], total[i], age[i], weight[i]);
		for(int ix=0; ix<m; ix++) fprintf(output, "%d ", marks[i][ix]);
	}
	printf("%d ", max);
	for(int ix=0; ix<m; ix++) printf("%d ", highest_mark[ix]);
	printf("\n");
}

