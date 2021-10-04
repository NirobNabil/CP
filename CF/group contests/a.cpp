#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int n;
	scanf("%d", &n);
	bool running=true;
	char a[n];
	scanf("%s", &a);
	int x = 0;
	while(running) {
		running = false;
		for(int i=0; i<n; i++) {
			// printf("%d %s %d\n", i, a, running);
			if(a[i]=='L' && i>0) {
				if(a[i-1] == 'r') {
					a[i-1] = '.';
				}else if(a[i-1] == 'R' || a[i-1] == 'L'){
					continue;
				}else {
					a[i-1] = 'l';
				}
			}else if(a[i] == 'R' && i<n) {
				if(a[min(n-1, i+1)] == 'l') {
					a[min(n-1, i+1)] = '.';
				} else if(a[min(n-1, i+1)] == 'L' || a[min(n-1, i+1)] == 'R'){
					continue;
				}else {
					a[min(n-1, i+1)] = 'r';
				}
			}
		}
		// printf("\n");
		for(int i=0; i<n; i++) {
			if(a[i] == 'r') a[i]='R', running=true;
			if(a[i] == 'l') a[i]='L', running=true;
		}
	}
	// printf("%s\n", a);
	for(int i=0; i<n; i++) {
		if(a[i] == '.') x++;
	}
	printf("%d\n", x);
}