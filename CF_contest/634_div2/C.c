#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int students[200001];

int main(){
	int t, max, total;
	scanf("%d", &t);
	while(t--){
		max=0;
		total=0;
		memset(students, 0, sizeof(students));
		int n, temp_student;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &temp_student);
			students[temp_student]++;
		}
		for(int i=0; i<200001; i++){
			max = MAX(students[i], max);
			if(students[i]!=0) total++;
		}
		if(max == total) printf("%d\n", MAX(0,max-1));
		else printf("%d\n", MIN(total, max));
	}
}