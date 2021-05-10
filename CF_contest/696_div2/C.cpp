#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int _lower_bound(vector<int> v, int l, int r, int x) {
	int mid = (r+l)/2;
	while(l!=r && l+1!=r) {
		printf("%d %d %d\n", l, v[mid], r);
		if(v[mid]>x) {
			r = mid;
		}else l = mid;
		mid = (r+l)/2;
	}
	if(v[r]==x) return r;
	else if(v[l]==x) return l;
	else return -1;
}

multiset<int>::iterator _lower_bound(multiset<int> s, int i) {
	multiset<int>::iterator x = s.lower_bound(i);
	if(*x == i) return x;
	else return s.end();
}

int main(){
	int n, t, tt;
	scanf("%d", &t);
	while(t--) {
		std::vector<int> v;
    multiset<int> s, ts;
		scanf("%d", &n);
		for(int i=0; i<n*2; i++) {
			scanf("%d", &tt);
			v.push_back(tt);
    	s.insert(tt);
		}
    sort(v.begin(), v.end());
    v.pop_back();
    int z,d=0, ty;
    for(int i=0; i<v.size(); i++)  {
	    std::vector<pair<int,int> > ans;
    	ts.clear();
      ts = s;
      auto x = ts.end();
      auto y = ts.rend();
      while(ts.size()>1) {
      	y = ts.rbegin();
      	ty = *y;
      	// dbg(ty);
      	ts.erase(next(y).base());
      	x = (x==ts.end())?x=ts.find(v[i]):ts.find(z-ty);
      	// dbg(*x);
      	if(x==ts.end()) {
      		break;
      	}
      	ans.push_back({*x,ty});
      	z = ty;
      	ts.erase(x);
      }
      // printf("DONE\n");
      if(ts.size()==0) {
      	printf("YES\n%d\n", v[i]+*s.rbegin());
      	for(auto i:ans) {
	      	printf("%d %d\n", i.X, i.Y);
      	}
      	d=1;
      	break;
      }
      // printf("DONE\n");
    }
		if(d==0) printf("NO\n");
	}
	// printf("gg\n");
	// cerr << "XD";
}
