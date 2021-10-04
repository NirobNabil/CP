#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t=1;
	// scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		std::vector<int> ans1, ans2;
		int i=1;
		if(n==2 || n==3) {
			printf("NO SOLUTION\n");
			continue;
		}
		if(n==1) {
			printf("1\n");
			continue;
		}
		if(n%2==1) printf("%d ", n), n--;
		for(; i<=n/2; i++) {
			if(i==n/2-1) ans1.push_back(n/2), ans1.push_back(n/2-1), i++;
			else ans1.push_back(i);
		}
		for(; i<=n; i++) ans2.push_back(i);
		auto i1=ans1.begin();
		auto i2=ans2.rbegin();
		for(; i1!=ans1.end() || i2!=ans2.rend(); i1++, i2++){
			printf("%d %d ", *i1, *i2);
		} 
	}
}