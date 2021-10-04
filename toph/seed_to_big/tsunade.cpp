#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define len 1000

struct Info{
	int x,rc,c,next;
};

int t, n, k, j;
vector<int> a;
unordered_map<int, Info > r;

int build(int i){
	if(r.find(i) != r.end()) {
		// printf("gg %d - %d\n", i, r[i].c);
		return r[i].c;
	}
	else if(i==a.size()-1) {
		printf("xx %d\n", i);
		r[i] = {i,k+0,k+0,-1};
		return k;
	}
	printf("in %d\n", i);
	int ix=i,j=0,h;

	while(a[ix]==a[i]) ix++;
	h=k+build(ix);
	r[i] = {a[i], k, h, ix};
	printf("- %d ix - %d - %d, %d\n", i, ix, j, h);
	
	for(; ix<a.size(); ix++) {
		if(a[ix]<=a[i]+j*2) continue;
		
		j = (a[ix]-a[i]-1)/2+1;
		if(ix!=a.size()-1) h = k+j+build(ix+1);
		else h=k+j;
		printf("- %d ix - %d - %d, %d\n", i, ix, j, h);
		if(h<=r[i].c) {
			// printf("replacing r[%d] by %d\n", i, h);
			printf("r[%d].rc = %d - %d %d %d\n", i, k+j, ix, k, j);
			// r[i].x = a[i]+j;
			// r[i].c = h;
			// r[i].rc = k+j;
			// r[i].next = (ix!=a.size()-1)?ix+1 : -1;
			r[i] = { a[i]+j, j, h, (ix!=a.size()-1)?ix+1 : -1};
			// r[i] = {a[i] + j, h, ix+1};
		}
	} 
	
	printf("out %d - %d\n", i, r[i].c);
	return r[i].c;
}

int main(){
	scanf("%d", &t);
	while(t--){
		a.clear();
		r.clear();
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++) scanf("%d", &j), a.push_back(j);
		// printf("%d\n", a.size());
		int cost = build(0);
		int i=0, n=0;
		while(1){
			n++;
			if(r[i].next == -1) break;
			i = r[i].next;
		}
		printf("%d %d\n", n, cost);
		i=0;
		while(1){
			printf("%d %d\n", r[i].x, r[i].rc);
			if(r[i].next == -1) break;
			i = r[i].next;
		}
	}
}