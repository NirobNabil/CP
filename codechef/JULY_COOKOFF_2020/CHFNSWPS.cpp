#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, n, x;
	scanf("%d", &t);
	while(t--){
		map<int, int>> dA, dB, A, B;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			if(A[x]) dA[x]=A[x], A[x]=-1;
			A[x]=i;
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			if(A[x] == A.end() && ){
				printf("-1\n");
				break;
			}
			if(B[x]) dB[x]=B[x], B[x]=-1;
			B[x]=i;
		}
		for(auto i : )
	}
}