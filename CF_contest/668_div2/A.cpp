#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,h;
		scanf("%d", &n);
		std::vector<int> v;
		for(int i=0; i<n; i++) scanf("%d", &h), v.push_back(h);
		for(auto i=v.rbegin(); i!=v.rend(); i++) printf("%d ", *i);
		printf("\n");
	}
}