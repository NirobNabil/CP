#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	ll t,i;
	scanf("%lld", &t);
	string ans;
	if(t==0) {
		printf("10\n");
		return 0;
	} 
	while(t>9){
		for(i=9; i>=2; i--) {
			if(t%i==0) { t /= i; ans+=i+'0'; break; }
		}
		if(i==1) {
			printf("-1\n");
			return 0;
		}
	}
	ans += t+'0';
	for (auto x = ans.rbegin(); x != ans.rend(); ++x){
		cout << *x;
	}
	cout << "\n";
}