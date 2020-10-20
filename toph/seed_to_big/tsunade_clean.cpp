// #include "bits/stdc++.h"
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
#include <climits>
#define MAX_N 5006
using namespace std;
#define ll long long int

// contains info about current tower and next tower
// x=tower position,  rc=cost to build this tower,  c= rc + cost of building all the towers polled by next
struct Info{
	ll x,rc,c,next;
};

ll t, n, k, j;
vector<ll> a(MAX_N);  //contains position of shops
unordered_map<ll, Info > r(MAX_N);   //contains tower info for ith position of array A

ll build(ll i){
	if(r.find(i) != r.end()) return r[i].c;  //return if optimum value for shops from i to n-1 has already been calculated
	if(i==a.size()-1) {
		r[i] = {a[i],0,k+0,-1};  //basecase - place one tower at position i costing k. -1 says there are no towers after this
		return k;
	}
	ll ix=i,j=0,h;
	r[i] = {-1, -1, INT_MAX, -1};
	for(; ix<a.size(); ix++) {
		j = (a[ix]-a[i]!=0) ? (a[ix]-a[i]-1)/2+1 : 0;  //calculate range of the tower to build to cover all shops from i to ix 
		if(ix!=a.size()-1) h = k+j+build(ix+1);   //calculate combined total cost for current tower and all towers after it
		else h=k+j;
		// printf("%ld %ld %ld\n", i, ix, h);
		if(h<=r[i].c) {
			r[i] = { a[i]+j, j, h, (ix!=a.size()-1)?ix+1 : -1};  //if new cost is less than current cost, replace the current one
		}
	} 

	return r[i].c;
}

int main(){
	scanf("%lld", &t);
	while(t--){
		a.clear();
		r.clear();
		scanf("%lld %lld", &n, &k);
		for(ll i=0; i<n; i++) scanf("%lld", &j), a.push_back(j);
		sort(a.begin(), a.end());
		if(n==0) { printf("0 0\n"); continue; }
		ll cost = build(0), i=0, tn=0;
		while(1 && tn<=n){   				//calculate the number of towrs
			tn++;
			if(r[i].next == -1) break;
			i = r[i].next;	
		}
		printf("%lld %lld\n", tn, cost);
		i=0;
		while(tn--){
			printf("%lld %lld\n", r[i].x, r[i].rc);
			if(r[i].next == -1) break;
			i = r[i].next;
		}
	}
}