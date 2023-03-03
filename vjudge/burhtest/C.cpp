#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, a[100009];
	int n;
	set<int> b;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n+5; i++) {
		b.insert(i);
	} 
	for(int i=0; i<n; i++) {
		b.erase(a[i]);
	}
	map<int, int> entered;
	vector<int> ans;
	ans.push_back(*b.begin());
	b.erase(b.begin());
	for(int i=0; i<n-1; i++) {
		if(a[i]==a[i+1]) {
			ans.push_back(*b.begin());
			b.erase(b.begin());
			continue;
		}
		else {
			ans.push_back(a[i]);
		}
	}
	for(auto i:ans) printf("%d ", i);
	printf("\n");
}