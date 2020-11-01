#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a>b)?b:a)

int checkLeap(int y){
    if (((y % 4 == 0) && (y % 100!= 0)) || (y%400 == 0))
       return 1;
    else
       return 0;
}

int main(){
	int t;
	scanf("%d", &t);
	int ix=1;
	char month1[10], month2[10];
	int date1, year1, date2, year2;
	for(;ix<=t; ix++){
		scanf("%s %d, %d", month1, &date1, &year1);
		scanf("%s %d, %d", month2, &date2, &year2);
		if(year1>year2){
			int Tyear=year2, Tdate=date2;
			char Tmonth[10];
			strcpy(Tmonth, month2);
			year2=year1;
			date2=date1;
			strcpy(month2, month1);
			year1=Tyear;
			date1=Tdate;
			strcpy(month1, Tmonth);
		}
		if(!(strcmp("January", month1)==0) && !(strcmp("February",month1)==0)) year1++;
		if(strcmp("January", month2)==0 || ( strcmp("February",month2)==0 && date2!=29)) year2--;
		//printf("%d\n", strcmp("February",month2));
		int leaps=0;
		printf("%s %d %d %d\n", month1, year1, year2, year2);
		for(int i=MIN(year1, year2); i<MAX(year1, year2); i++){
			leaps += checkLeap(i);
			//if(checkLeap(i)) printf("%d\n", i); 
		}
		printf("Case %d: %d\n", ix, leaps);
	}
}