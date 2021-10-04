#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	bool f=true;
	scanf("%d", &t);
	char s[10];
	while(t--){
		scanf("%s", &s); 
		f=true;
		for(int i=strlen(s)-1; i>=0; i--){
			if(f && s[i]=='0') continue;
			f = false; 
			printf("%c", s[i]);
		}
		printf("\n");
	}
}