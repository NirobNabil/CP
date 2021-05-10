#include <stdio.h>
#include <string.h>

int main(){
	char str[20];
	scanf("%s", str);
	int len = strlen(str);
	for(int i=0; i<len/2; i++){
		if(str[i] != str[len-i-1]){
			printf("not pal\n");
			return 0;
		}
	}
	printf("pal\n");
}