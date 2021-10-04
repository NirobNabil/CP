#include "bits/stdc++.h"
using namespace std;
#define ll long long int

unordered_map< int, vector<pair<pair<int, int>,int> > > a((int)1e5 + 100);
pair<pair<ll,int>, pair<ll,int> > c[(int)1e5 + 100];
// vector<pair<pair<int,int>, int> > d;

int traverse(int node, int parent){
	if( a[node].size()==1 && (*a[node].begin()).first.first==parent) {
		if(c[node].second.second>1){
			c[node].first.first = ((c[node].second.first - c[node].second.first/2)*c[node].second.first)/2+((c[node].second.first - c[node].second.first/2)*c[node].second.first)%2;
		}else c[node].first.first = c[node].second.first-(c[node].second.first/2);
		c[node].first.second = 1;
		return 1; //found leaf	
	}
	int t = 0;
	for(auto i:a[node]) {
		if(i.first.first != parent) {
			c[i.first.first].second.first = i.first.second;
			c[i.first.first].second.second = i.second;
		 	t += traverse(i.first.first, node);
		}
	}
	// printf("%d %d\n", node, c[node].second.second*2);
	if(c[node].second.second>1){
		c[node].first.first = ((c[node].second.first-c[node].second.first/2)*t)/2 + ((c[node].second.first-c[node].second.first/2)*t)%2;
	}else c[node].first.first = (c[node].second.first*t)-(c[node].second.first/2)*t;
	c[node].first.second = t;
	return t;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		a.clear();
		priority_queue<pair<pair<ll, int>, pair<ll,int> > > b;
		// b.clear();
		// memset(c, 0, sizeof(c));
		int n, x,y,z,zx;
		ll s;
		scanf("%d %lld", &n, &s);
		for(int i=0; i<n-1; i++) {
			scanf("%d %d %d %d", &x, &y, &z, &zx);
			a[x].push_back(make_pair(make_pair(y,z),zx));
			a[y].push_back(make_pair(make_pair(x,z),zx));
		} 
		int hx, hy;
		ll sum = 0, count=0;
		pair<pair<ll,int>, pair<ll,int> > h;
		// for(int i=1; i<n; i++) cout << cost[i] << " ";
		// printf("\n");
		c[1] = make_pair(make_pair(0,0), make_pair(0,1));
		traverse(1, 1);

		for(int i=1; i<=n; i++) b.push(c[i]), sum+=c[i].second.first*(c[i].first.second==0?1:c[i].first.second), printf("%d ", c[i].second.first*c[i].first.second);
		printf("\n%d\n", sum);
		while(sum > s) {
			h = b.top();
			count += h.second.second;
			b.pop();
			if(h.second.second) {
				// if(((h.second.first - h.second.first/2)*h.first.second)%2==1) sum-=1;
				sum -= ((h.second.first - h.second.first/2)*h.first.second);
			}else sum -= h.first.first;
			printf("%lld %lld %d - ", h.first.first, h.first.second, h.second.first);
			h.second.first /= 2;
			printf("%lld %d %lld\n", (h.second.first*h.first.second)-(h.second.first/(h.second.second*2))*h.first.second, h.first.second, h.second.first);
			// hy = h.second.second==0?1:h.second.second;
			if(h.second.second>1){				
				b.push(make_pair(make_pair(((h.second.first - h.second.first/2)*h.first.second)/2 + ((h.second.first - h.second.first/2)*h.first.second)%2, h.first.second), h.second));
			}else b.push(make_pair(make_pair((h.second.first*h.first.second)-(h.second.first/2)*h.first.second, h.first.second), h.second));	
		}
		printf("%lld\n", count);
	}
}