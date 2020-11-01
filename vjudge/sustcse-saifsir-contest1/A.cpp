#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define MUL(A,B,C)	(max(A*C, B*C))
int main(){
	ll a[4];
	for(int i=0; i<4; i++)  scanf("%lld", &a[i]);
	printf("%lld\n", max(MUL(a[0],a[1],a[2]), MUL(a[0],a[1],a[3])));
}