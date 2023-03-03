#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

int main(){
	int x,t,e;
	scanf("%d %d", &t, &x);
	int gg = 2*x + 2*t;
	// int xd = sqrt(gg);
	// printf("g - %d\n", gg);
	for(int i=1; i<100000; i++) {
		if(i*(i+3)==gg) {printf("%d\n", t-i); break; }
		// printf("%d %d %d\n", i, i*(i+3), t-i);
	} 
}