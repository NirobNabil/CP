#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, maxx=0, l=0;
		scanf("%d %d", &n, &k);
		int mountains[n], peaks[n]={0};
		for(int i=0; i<n; i++) scanf("%d", &mountains[i]);
		for(int i=1; i<n-1; i++) if(mountains[i]>mountains[i-1] && mountains[i]>mountains[i+1]) peaks[i]=1; 
		for(int i=1; i<n; i++) peaks[i] = peaks[i]+peaks[i-1];
		// for(int i=0; i<n; i++) printf("%d ", peaks[i]);
		// printf("\n");

		for(int i=n-1; i>=k-1; i--){
			if(peaks[i-1]-peaks[i-k+1]>=maxx) maxx=peaks[i-1]-peaks[i-k+1], l=i-k+1;
			//printf("%d %d\n", l, i-k+1);
		}
		printf("%d %d\n",maxx+1, l+1);
	}
}