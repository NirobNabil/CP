#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

ll a[100009][2], b[100009][2], cm[100009+1][2];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%lld", &a[i][0]);
	for(int i=0; i<n; i++) scanf("%lld", &a[i][1]);
	// for(int i=0; i<=n; i++) cm[i][0]=0, cm[1][0]=0;
	for(int i=n-1; i>=0; i--) {
		b[i][0] = a[i][0] + cm[i+1][1];
		b[i][1] = a[i][1] + cm[i+1][0];
		cm[i][0] = max(cm[i+1][0], b[i][0]);
		cm[i][1] = max(cm[i+1][1], b[i][1]);
	}
	printf("%lld\n", max(cm[0][1], cm[0][0]));
}