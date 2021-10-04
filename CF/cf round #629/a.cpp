#include <bits/stdc++.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a,b, res;
		scanf("%d %d", &a, &b);
		if(a%b) res = (a/b+1)*b - a;
		else res = 0;
		printf("%d\n", res);
	}
	return 0;
}