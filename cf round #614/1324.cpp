#include <bits/stdc++.h>

using namespace std;

char road[200000];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", road);
		int len = strlen(road), jump=0, lastR=-1;
		//printf("%d %s %d\n",t, road, len);
		for(int i=0; i<=len; i++){
			if(road[i] == 'R' || i==len) jump = max(jump, i-lastR), lastR=i;
		}
		printf("%d\n", jump);
	}
}