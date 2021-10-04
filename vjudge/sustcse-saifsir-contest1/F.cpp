#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a*b)/__gcd(a,b));
}