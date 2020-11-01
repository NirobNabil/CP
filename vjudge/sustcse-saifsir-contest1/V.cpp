#include "bits/stdc++.h"
using namespace std;
#define ll long long int

char gg[10];
bool check(int a){
	sprintf(gg, "%d", a);
	return gg[0]==gg[4] && gg[1]==gg[3];
}

int main(){
	int a,b,r=0;
	scanf("%d %d", &a, &b);
	a--;
	while(a++ < b){
		r += check(a);
	}
	printf("%d\n", r);
}