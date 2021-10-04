#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int mul[2][1000000]={0}, check[2][1000000]={0};

int main(){
	int n;
	scanf("%d", &n);
	int a[2][n+5], m=0;
	for(int i=0; i<n; i++) scanf("%d", &a[0][i]), check[0][a[0][i]]=1, m = max(m, a[0][i]);
	for(int i=0; i<n; i++) scanf("%d", &a[1][i]), check[1][a[1][i]]=1, m = max(m, a[1][i]);
	for(int i=1; i<=m; i++) {
		for(int ii=i; ii<=m; ii+=i) {
			if(check[0][ii]) mul[0][i] = ii;
			if(check[1][ii]) mul[1][i] = ii;
		}
	}
	int gg=0;
	for(int i=1; i<=m; i++) {
		// printf("%d %d\n", mul[0][i], mul[1][i]);
		if(mul[0][i] && mul[1][i]) {
			gg = i;
		}
	}
	cout << mul[0][gg] + mul[1][gg] << endl;
}