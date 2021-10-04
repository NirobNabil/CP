#include "bits/stdc++.h"
using namespace std;
#define ll long long int

char a[] = {'0','1','2','3','4','5','6','7','8','9'};
char s[200005];

int check(char x, char y, int l){
	int i=0, r=0;
	char z=x;
	for(; i<l; i++) {
		if(s[i]==z) r++, z=(z==x)?y:x;
	}
	return (r==1 || x==y)?r:r-r%2;
}

int main(){
	int t, l, res;
	scanf("%d", &t);
	while(t--){
		res=INT_MIN;
		scanf("%s", s);
		l = strlen(s);
		for(int i=0; i<10; i++){
			for(int ix=0; ix<10; ix++) {
				// printf("%c %c %d\n", a[i], a[ix], check(a[i],a[ix],l));
				res = max(res, check(a[i],a[ix],l));
			}
		}
		printf("%d\n", l-res);
	}
}