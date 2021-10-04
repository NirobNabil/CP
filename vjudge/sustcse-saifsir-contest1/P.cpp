#include "bits/stdc++.h"
using namespace std;
#define ll long long int
const ll mod = 1000000007;

int pp_s[100000]={0};

int pp(int n){
	if(n<3) return 0;
	else if(n==3) return 1;
	else if(pp_s[n]) return pp_s[n];
	else {
		int r=1;
		for(int i=n-3; i>=3; i--) {
			r = (r+pp(i))%mod;
		}
		pp_s[n] = r;
		return r;
	}
}

int main(){
	int s;
	scanf("%d", &s);
	printf("%d\n", pp(s));
}