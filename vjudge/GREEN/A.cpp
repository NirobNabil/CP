#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 1000009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

ll cnt[S1];
int n, m, x, y;
vector<pair<int,int> > s;
ll xxx=0;

ll chk(int a) {
	if(s[a].Y == n) cnt[a]=1;
	// printf("x - %d %d\n", a, s[a].Y);
	if(cnt[a] != -1) return cnt[a];
	ll count = 0;
	for(int i=0; i<m; i++) {
		// cerr << s[a].X << " " << s[i].Y << endl; 
		xxx++;
		if(s[i].X > s[a].Y) {
			cerr << "xd\n";
			break;
		}
		// cerr << a << i << "came0" << endl;
		if(s[i].Y <= s[a].Y) continue;
		// cerr << a << i << "came1" << endl;
		if(i == a) continue;
		// cerr << a << i << "came2" << endl;
		// if(xxx%10==0) cerr << xxx << endl;
		count = (count+chk(i))%(ll)1000000007;
	} 	
	cnt[a] = count;
	return cnt[a];
}

int main(){
	memset(cnt, -1, sizeof(cnt));
	scanf("%d %d", &n, &m);
	cerr << n << m << endl;
	for(int i=0; i<m; i++)  {
		scanf("%d %d", &x, &y), s.push_back({x,y});
	}
	sort(s.begin(), s.end());
	ll ans=0;
	for(int i=0; i<m; i++) {
		if(s[i].X!=0) break;
		ans = (ans+chk(i))%(ll)1000000007;
		cerr << "gg";
	}
	printf("%lld\n", ans);
}