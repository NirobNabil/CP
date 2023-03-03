#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


int main(){
	int i, ix, t, n, m, k, p, gg, x, y, z;
	while(scanf("%d", &n) && n==100000) {
		scanf("%d", &k);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
	    	scanf("%d", &a[i]);
	    }
	    vector<pair<pp, int> > q;
	    for(int i=0; i<k; i++) {
	    	scanf("%d %d", &x, &y);
	    	q.emplace_back(make_pair(x,y),i);
	    }

	    int rn = sqrt(k);
	    sort(q.A(), q.B(), [&](pair<pp,int> &a, pair<pp,int> &b) {
	    	if(a.X.X/rn == b.X.X/rn) {
	    		return a.X.Y > b.X.Y;
	    	}else return (a.X.X/rn) < (b.X.X/rn);
	    });

	    int st=0, end=0;
	    set<pp> f;
	    unordered_map<int,int> fm;
	    vector<int> ans(k);
	    fm[a[end]]++;
	    f.insert({fm[a[end]], a[end]});

	    auto update = [&](int l, int r) {
	    	while(end > r) {
	    		f.erase({fm[a[end]], a[end]});
	    		fm[a[end]]--;
	    		f.insert({fm[a[end]], a[end]});
	    		end--;
	    	}
	    	while(end < r) {
	    		end++;
	    		fm[a[end]]++;
				f.erase({fm[a[end]]-1, a[end]});
	    		f.insert({fm[a[end]], a[end]});
	    	}
	    	while(st < l) {
	    		f.erase({fm[a[st]], a[st]});
	    		fm[a[st]]--;
	    		f.insert({fm[a[st]], a[st]});
	    		st++;
	    	}
	    	while(st > l) {
	    		st--;
	    		fm[a[st]]++;
	    		f.erase({fm[a[st]]-1, a[st]});
	    		f.insert({fm[a[st]], a[st]});
	    	}
	    };

	    for(int i=0; i<k; i++) {
	    	update(q[i].X.X-1, q[i].X.Y-1);
	    	ans[q[i].Y] = f.rbegin()->X;
	    }

	    debug(q);
	    for(auto i:ans) {
	    	printf("%d\n", i);
	    }
	}

}