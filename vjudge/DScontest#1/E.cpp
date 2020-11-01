#include "bits/stdc++.h"
using namespace std;
#define ll long long int

ll a[100005], r[100005][2];
bitset<100005> d;
ll n;

int follow(int i, int ai){
	if(i<0 || a[i] != ai || !d[i]) return 0;
	r[i][0] += follow(i-r[i][0], ai);
	d[i]=0;
	return r[i][0];
}

int main(){
	while(scanf("%ld", &n) && n) {
		d.reset(0);
		for(ll i=0; i<n; i++) {
			scanf("%ld", &a[i]);
			r[i][0] = 1;
			for(ll ix=i-1; ix>-1;) {
				if(a[ix]>a[i]) { 
					r[ix][1]=min(r[ix][1],i-ix-1);
					r[i][0]+=r[ix][0]; 
					ix-=r[ix][0];
				}else if(a[ix]==a[i]) { 
					d[i]=1;
					d[ix]=1;
					r[i][0]=i-ix;// sames[i] = sames[ix]; sames[i].insert(ix); 
					break;
				}
				else break;
			}
			r[i][1] = n-i-1;
		}
		ll x=0;
		for(int i=0; i<n; i++) {
			if(d[i]) follow(i, a[i]);
			x = max(x, a[i]*(r[i][0]+r[i][1]) );
		}
	  printf("%lld\n", x);
	}
}