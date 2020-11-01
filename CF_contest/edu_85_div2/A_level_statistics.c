#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int plays=0, clears=0, n=0, yes=1;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			//printf("%d %d\n", t, i);
			int p,c;
			scanf("%d %d", &p,&c);
			//printf("%d %d %d %d\n", p, plays, p-plays, c-clears);
			if(p<plays || c<clears || p-plays<c-clears) yes = 0;
			plays = p;
			clears = c;
		}
		if(yes==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}