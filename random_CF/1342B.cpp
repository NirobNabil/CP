#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		char in[101];
		scanf("%s", in);
		int ones=0, zeroes=0;
		for(int i=0; i<strlen(in); i++){
			if(in[i] == '0') zeroes++;
			else ones++;
		}
		if(ones==0 || zeroes==0) printf("%s\n", in);
		else{
			int s = max(ones, zeroes);
			char ans[201]="";
			while(s--){
				strcat(ans, "10");
			}
			printf("%s\n", ans);
		}
		// printf("%d %d\n", ones, zeroes);
	}
	return 0;
}