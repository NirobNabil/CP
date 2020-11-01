#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, t;
		scanf("%d", &n);
		multiset<int> a, b;
		int c[n*2];
		for(int i=0; i<n; i++) scanf("%d", &t), a.insert(t);
		int m = INT_MIN;
		if(n==1) {
			printf("0\n");
			continue;
		}
		multiset<int>::iterator x, y;
		int count=0, c_count=0, gg=0, xx=-1;
		for(int i=1; i<=n*2; i++){
			b = a;
			y = b.end();
			c_count=0;
			x = b.begin();
			while(b.size()>1 && x!=b.end()){
				// for(auto ii : b) cout << ii << " ";
				// cout << endl;
				if(xx==-1) x = b.begin();

				// printf("%d %d ", i, *x);
				if(*x<i) gg = i-*x;
				else {
					x++;
					xx = 0;
					continue;
				}

				y = b.find(gg);
				if(y!=b.end() && x!=y) {
					b.erase(x); b.erase(y); c_count++; //printf("%d ", c_count);
				}else if(y!=b.end() && x==y) {
					if(b.count(gg)>1) {
						b.erase(x);
						b.erase(b.find(gg));
						c_count++;
						 // printf("%d ", c_count);
					}else{
						b.erase(x);
					}
				}else b.erase(x);
				// printf("\n");
				xx = -1;  
			}
			// printf("i=%d\n", i);
			count = max(count, c_count);
		} 
				
		printf("%d\n", count);
	}
}