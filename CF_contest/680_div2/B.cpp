#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a[4];
		for(int i=0; i<4; i++) scanf("%d", &a[i]);
		printf("%d\n", max(a[0]+a[1], a[2]+a[3]));
	}
}