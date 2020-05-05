#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int actualN, n, a, b, c, d;
		scanf("%d %d %d %d %d", &actualN, &a, &b, &c, &d);
		n = actualN;
		//printf("xd %d\n", );
		if(n*(a-b)>c+d || n*(a+b)<c-d) printf("No\n");
		else{
			while(n*(a-b)<c-d) n--, d += a+b;
			// printf("t %d %d\n", t, n);
			//if(n==0) printf("%s\n", );
			if(n*(a-b)>c+d){
				// printf("gg\n" );
				if((n*(a-b)-(c+d))/(actualN-n)+((n*(a-b)-(c+d))%(actualN-n)>0)?1:0 < b+b) printf("Yes\n");
				else printf("No\n");
			}else if(n*(a-b) <= c+d && n*(a-b) >= c-d) printf("Yes\n");
		}
	}
}