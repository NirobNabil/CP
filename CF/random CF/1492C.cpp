#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 300009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define bg begin
#define en end

char s[S1], t[S1];
int i, ix, n, m;
unordered_map<char, vector<int> > p;
std::vector<int> a, b;

int _lower_bound(vector<int> &v, int l, int r, int x, std::vector<int> &a) {
	int mid = (r+l)/2;
	// printf("%d ", x);
	while(l!=r && l+1!=r) {
		if(a[v[mid]]>=x) {
			r = mid;
		}else l = mid;
		mid = (r+l)/2;
	}
	if(a[v[l]]>=x) return v[l];
	else return v[r];
}


int _lower_bound2(vector<int> &v, int l, int r, int x, std::vector<int> &a) {
	int mid = (r+l)/2;
	// printf("%d ", x);
	while(l!=r && l+1!=r) {
		if(a[n-1-v[mid]]>=x) {
			l = mid;
		}else r = mid;
		mid = (r+l)/2;
	}
	if(a[n-1-v[r]]>=x) return v[r];
	else return v[l];
}



int main(){
	scanf("%d %d", &n, &m);			
	clock_t gg = clock();
	scanf("%s %s", s, t);
	for(int i=0; i<n; i++) {
		p[s[i]].pb(i);
	}
	for(int i=0, ix=0; i<n; i++) {
		if(ix<m && s[i]==t[ix]) ix++;
		a.pb(ix);
	}
	for(int i=n-1, ix=m-1; i>=0; i--) {
		if(ix>=0 && s[i]==t[ix]) ix--;
		b.pb(m-1-ix);
	}
	// printf("asdas\n");
	// for(int i=0; i<n; i++) {
	// 	printf("%d ", a[i]);
	// }	
	// printf("\n");
	// for(int i=0; i<n; i++) {
	// 	printf("%d ", b[i]);
	// }
	// printf("\n");
	// printf("%d\n", lower_bound(b.begin(), b.end(), 3) - b.begin());
	int mx=0;
	for(int i=0; i<m-1; i++) {
		// cout << t[i] << " ";
		// cout << i+1 << " " << _lower_bound(p[t[i]], 0, p[t[i]].size()-1, i+1, a) << "  ";
		// cout << m-1-i << " " <<_lower_bound2(p[t[i+1]], 0, p[t[i+1]].size()-1, m-1-i, b) << "\n";
		// if(i%100==0) cout << (float)(clock()-gg)/CLOCKS_PER_SEC << endl;
		mx = max(mx,
		  _lower_bound2(p[t[i+1]], 0, p[t[i+1]].size()-1, m-1-i, b)
			- _lower_bound(p[t[i]], 0, p[t[i]].size()-1, i+1, a));
	} 	
	printf("%d\n", mx);
}

/*
abccdcxyzd
abccd
*/