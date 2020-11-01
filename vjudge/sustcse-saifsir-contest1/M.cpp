#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, j, r=0;
	scanf("%d", &t);
	while(t--){
		r=0;
		for(int i=0; i<3; i++) scanf("%d", &j), r+=j;
		printf("%s\n", r==180?"YES":"NO");
	}
}