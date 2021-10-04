#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	char a[105];
	while(t--){
		scanf("%s", a);
		if(!next_permutation(a, a+strlen(a))) printf("no answer\n");
		else printf("%s\n", a);
	}
}