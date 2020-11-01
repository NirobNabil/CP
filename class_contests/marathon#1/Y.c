#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	char str[31];
	char out[31];
	while(scanf("%s", str) != EOF){
		unsigned int i=0;
		for(; i<strlen(str); i++){
			if(str[i]=='1' || str[i]=='0' || str[i]=='-') out[i] = str[i];
			else if(str[i] > 'R'){
				if(str[i] == 'S') out[i] = '7';
				else if(str[i] >= 'T' && str[i] <='V') out[i] = '8';
				else if(str[i] >= 'W' && str[i] <= 'Z') out[i] = '9';
			}
			else{
				out[i] = (int)ceil(((int)str[i] - 64)/3.0) + 1 + 48;
			}
		}
		out[i] = '\0';
		printf("%s\n", out);
	}
	return 0;
}