#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

int main(){
	int n, k, g;
	scanf("%d %d", &n, &k);
	std::vector<int> a;
	for(int i=0; i<n; i++) {
		scanf("%d", &g);
		a.push_back(g);
	}
	int ans=0;
	sort(a.begin(), a.end());
	for(int i=0; i<n-1; i++) {
		if(a[i]==a[i+1]) ans++, i++;
	}
	n = (n%2==1)?n+1:n;
	printf("%d\n", ans*2 + n/2 - ans);
}