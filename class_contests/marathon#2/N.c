#include <stdio.h>
#define MIN(a,b) ((a>b)?b:a)

int facts[1000001][2];

int main(){
	int i=1;
	for(; i<=1000000; i++){
		int n=i;
		facts[i][0]=0;
		facts[i][1]=0;
		while(n%2==0 && n!=0){
			n/=2;
			facts[i][1]++;
		}
		while(n%5==0 && n!=0){
			n/=5;
			facts[i][0]++;
		}
		facts[i][0]+=facts[i-1][0];
		facts[i][1]+=facts[i-1][1];
	}
	int t,ix=1;
	scanf("%d", &t);
	for(; ix<=t; ix++){
		int n,r,p,q;
		scanf("%d %d %d %d", &n,&r,&p,&q);
		int ans5 = facts[n][0]-facts[r][0]-facts[n-r][0]+(facts[p][0]-facts[p-1][0])*q;
		int ans2 = facts[n][1]-facts[r][1]-facts[n-r][1]+(facts[p][1]-facts[p-1][1])*q;
		printf("Case %d: %d\n", ix, MIN(ans2,ans5));
	}
}