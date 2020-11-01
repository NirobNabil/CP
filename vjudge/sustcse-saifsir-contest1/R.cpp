#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int n;
	scanf("%d", &n);
	char a[n+5];
	scanf("%s", &a);
	if(n%2==1) printf("No\n");
	else{
		if(!strncmp(a, a+n/2, n/2)) printf("Yes\n");
		else printf("No\n");
	}
}