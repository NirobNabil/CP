#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		bool r=1;
		unordered_map<char, int> b;
		scanf("%d", &n);
		char s[1005];
		for(int i=0; i<n; i++) {
			scanf("%s", s);
			int l = strlen(s);
			for(int i=0; i<l; i++) {
				b[s[i]]++;
			}
		}
		for(auto i : b){
			if(i.second!=n &&  i.second%n!=0) r=0;
		}
		if(r==0) printf("NO\n");
		else printf("YES\n");
	}
}