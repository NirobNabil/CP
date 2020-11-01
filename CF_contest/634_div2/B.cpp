#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		char str[n+1];
		int next=0;
		while(next<n){
			for(int i=0; i<b && next<n; i++){
				str[next++] = (char)('a'+i);
			}
		}
		str[next] = '\0';
		printf("%s\n", str);
	}
}