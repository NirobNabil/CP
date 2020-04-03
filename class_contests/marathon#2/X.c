#include <stdio.h>
#include <string.h>

int main(){
	char word[100];
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", word);
		if(strlen(word)>10) printf("%c%d%c\n", word[0], strlen(word)-2, word[strlen(word)-1]);
		else printf("%s\n", word);
	} 
	return 0;
}