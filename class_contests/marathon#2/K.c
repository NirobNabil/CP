#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char a[20],b[20];
		int no=0;
		scanf("%s %s", a, b);
		if(strlen(a) != strlen(b)) printf("No\n");
		else{
			int i=0;
			for(; i<strlen(a); i++){
				if(a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o' && a[i]!='u'){
					if(a[i]!=b[i]){
						printf("No\n"); 
						no=1;
						break;
					}
				}else{
					if(b[i]!='a' && b[i]!='e' && b[i]!='i' && b[i]!='o' && b[i]!='u'){
						printf("No\n");
						no=1;
						break;
					}
				}
			}
			if(no==0) printf("Yes\n");
		}
	}
}