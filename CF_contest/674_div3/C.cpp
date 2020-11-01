#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define CEIL(A,B) ((A%B==0)?A/B:A/B+1)

int bs(int h, int l, bool u){
	if(u){
		return h + CEIL((h-l),2);
	}else return h - CEIL((h-l),2);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, a=INT_MAX, b=INT_MAX, r=0;
		int h=CEIL(n,2), l=0;
		scanf("%d", &n);
		a = sqrt(n);
		for(int i=5; i>-5; i--) {
			if(b>CEIL(n,(1+a+i)) + a+i, b) {
				r = a+i;
			}
		}
		printf("%d\n", b);
	}
}