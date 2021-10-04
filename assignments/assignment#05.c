#include <stdio.h>

int main(){
	int total_class, attended_class;
	scanf("%d %d", &total_class, &attended_class);
	int attendence = ((float)attended_class/total_class)*100;
	printf("%d %d", attendence, (attendence/5 >= 12)? attendence/5-9 : 0);
}