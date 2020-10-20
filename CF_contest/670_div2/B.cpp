#include "bits/stdc++.h"
using namespace std;
#define ll long long int

#define minus_push c.push_back(*a.begin()); c.push_back(*(a.begin()+1)); a.erase(a.begin(), a.begin()+2);
#define plus_push c.push_back(*b.begin()); c.push_back(*(b.begin()+1)); b.erase(b.begin(), b.begin()+2);
#define zero_check *(b.begin()+1)!=0 && *b.begin()!=0

vector<ll> a,b,c,d;
long long int r, l;

// void pretty_print(const vector<ll>& v) {
//   static int count = 0;
//   cout << "cn " << (++count) << ": [ ";
//   for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
//   cout << "] " << endl;
// }


void check(){
	l = d[0] * d[1] * d[2] * d[3] * d[4];
	r = max(r, l);
}

void go(int offset, int k) {
  if (k == 0) {
    // pretty_print(d);
    check();
    return;
  }
  for (int i = offset; i <= c.size() - k; ++i) {
    d.push_back(c[i]);
    go(i+1, k-1);
    d.pop_back();
  }
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		a.clear();
		b.clear();
		c.clear();
		ll n,h;
		cin >> n;
		bool has_one=false;
		for(int i=0; i<n; i++){
			cin >> h;
			if(h<0) a.push_back(h);
			else {
				if(h>0) has_one=true;
				b.push_back(h);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		if(has_one){
			if(a.size()<5) {
				int ix=0;
				for(; ix<a.size(); ix++) {
					c.push_back(a[ix]);
				}
				for(int i=0; i<b.size() && ix<10; ix++, i++) {
					c.push_back(b[i]);
				}
			}else if(b.size()<5) {
				int ix=0;
				for(; ix<b.size(); ix++) {
					c.push_back(b[ix]);
				}
				for(int i=0; i<a.size() && ix<10; ix++, i++) {
					c.push_back(a[i]);
				}
			}else {
				int ix=0;
				for(; ix<5; ix++) {
					c.push_back(b[ix]);
				}
				for(int ix=0; ix<5; ix++) {
					c.push_back(a[ix]);
				}
			}
		}else {
			if(a.size()<5) {
				int ix=0;
				for(; ix<a.size(); ix++) {
					c.push_back(a[ix]);
				}
				for(int i=0; i<b.size() && ix<10; ix++, i++) {
					c.push_back(b[i]);
				}
			}else if(b.size()<5) {
				int ix=0;
				for(; ix<b.size(); ix++) {
					c.push_back(b[ix]);
				}
				for(auto i=a.rbegin(); i!=a.rend() && ix<10; ix++, i++) {
					c.push_back(*i);
				}
			}else {
				int ix=0;
				for(; ix<5; ix++) {
					c.push_back(b[ix]);
				}
				for(auto i=a.rbegin(); i!=a.rend() && ix<10; ix++, i++) {
					c.push_back(*i);
				}
			}		
		}
		sort(c.begin(),c.end());
		r=c[0] * c[1] * c[2] * c[3] * c[4], l=0;
		go(0,5);
		cout << r << endl;
	}
}