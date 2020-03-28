#include <stdio.h>
#include <string.h>

int main(){
	char n[1000001];
	int first=1;
	while(scanf("%s", n) != EOF){
		int leap=0, mod4=0, mod55=0, mod15=0, mod100=0, mod400=0;
		int i=0;
		for(; i<strlen(n); i++){
            mod4=(mod4*10+n[i]-'0')%4;
            mod55=(mod55*10+n[i]-'0')%55;
            mod15=(mod15*10+n[i]-'0')%15;
            mod100=(mod100*10+n[i]-'0')%100;
            mod400=(mod400*10+n[i]-'0')%400;
        }
        if(!first) printf("\n");
		if((mod4==0 && mod100!=0) || mod400==0){
			printf("This is leap year.\n");
			leap=1;
		}
		if(mod15==0) printf("This is huluculu festival year.\n");
		if(mod55==0 && leap==1) printf("This is bulukulu festival year.\n");
		if(leap==0 && mod15!=0 && mod55!=0) printf("This is an ordinary year.\n");
		first=0;
	}
	return 0;
}