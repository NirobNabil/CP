#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, n, a, b;
	char x[10], y[10];
	scanf("%d", &t);
	while(t--){
		int r=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s %s", &x, &y);
			a=b=0;
			for(int i=0; i<strlen(x); i++) a += x[i] - '0'; 
			for(int i=0; i<strlen(y); i++) b += y[i] - '0'; 
			if(a>b) r++;
			else if(b>a) r--;
		}
		if(chef>morty) printf("0 %d\n", chef);
		else if(chef<morty) printf("1 %d\n", morty);
		else printf("2 %d\n", chef);
	}
}