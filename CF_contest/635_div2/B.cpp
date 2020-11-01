#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int h, n, m;
		scanf("%d %d %d", &h, &n, &m);
		while(h>20 && n--) h = h/2 + 10;
		while(h && m--) h-=10;
		if(h<=0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}