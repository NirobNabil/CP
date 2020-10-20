#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define CEIL(a,b) (a%b == 0 ? a/b : a/b+1)
int P[int(10e5)];

int main(){
	int t, n, x, temp;
	scanf("%d", &t);
	while(t--){
		int teams=0;
		scanf("%d %d", &n, &x);
		for(int i=0; i<n; i++) {
			scanf("%d", &P[i]);
			P[i] = CEIL(x, P[i]);
		}
		sort(P, P+n, less<int>());
		// for(int i=0; i<n; i++) {
		// 	printf("%d ", P[i]);
		// }
		for(int i=0; i<n;) {
			temp = P[i];
			int ix=0;
			for(; ix<temp && i+ix<n; ix++) {
				// printf("ix-%d  i-%d  P[i+ix]-%d \n", ix, i, P[i+ix]);
				// P[i+ix] = -1;
				temp = P[i+ix];
				if(ix+1==temp) {
					// printf("temp-%d  teams++\n", temp);
					teams++; 
					break;	
				}
				// printf("temp-%d\n", temp);
			}
			i += ix+1;
		}
		printf("%d\n", teams);
	}
}