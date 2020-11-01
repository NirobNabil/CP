#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#define MAX_N 1000000

int main() {
	FILE *input;
	input = fopen("input.txt", "r");
	FILE *output;
	output = fopen("output.txt", "r");
	FILE *answer;
	answer = fopen("answer.txt", "r");

	int t, h;
	fscanf(input, "%d", &t);
	std::bitset<MAX_N+5> shops;
	while(t--){
		shops.reset();
		int i_n,i_k, a_n, a_c, o_n, o_c, test_cost=0;
		fscanf(input, "%d %d", &i_n, &i_k);
    fscanf(answer, "%d %d", &a_n, &a_c);
		fscanf(output, "%d %d", &o_n, &o_c);
		if(a_c != o_c){
			printf("%d\n", 1);
			return 0;
		}
		for(int i=0; i<i_n; i++) {
			fscanf(input, "%d", &h);
		  shops[h] = 1;
    }
    int p, j;
    for(int i=0; i<o_n; i++) {
      fscanf(output, "%d %d", &p, &j);
      test_cost += i_k+j;
      for(int ix=0; ix<=j; ix++) {
        shops[(p+ix<MAX_N)?p+ix:MAX_N]=0;
        shops[(p-ix>0)?p-ix:0]=0;
      }
    }
    for(int i=0; i<a_n; i++){
      fscanf(answer, "%d %d", &p, &j); 
    } 
    if(shops.any() || test_cost!=o_c) {
    	// printf("%d %d\n", test_cost, o_c);
      printf("%d\n", 1);
      return 0;
    }    
	}
  printf("%d\n", 0);
  return 0;

}
