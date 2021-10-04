#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, a=0;
	scanf("%d", &t);
	char s[11];
	sprintf(s, "%d", t);
	for(int i=0, g=strlen(s); i<g; i++) {
		a += s[i]-'0';
	}
	printf("%s\n", t%a ? "No" : "Yes");
}