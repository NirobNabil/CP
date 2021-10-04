#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t, h;
	scanf("%d", &t);
	set<int> g;
	while(t--){
		g.clear();
		for(int i=0; i<3; i++) scanf("%d", &h), g.insert( h );
		printf("%d\n", *(++g.begin()));
	}
}