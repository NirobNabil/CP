#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int is_digit(char c) {
	return c < 58 && c > 47;
}

int main(){
	int i, ix, t, n, k;
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cin >> t;
	while(t--){
		string s; 
		cin >> s >> k;
		vector<pair<int, char> > v;
		for(int i=0; i<s.size(); i++) {
			string n = "0";
			while(is_digit(s[i])) n += s[i], i++;
			char c = s[i];
			ll num;
			sscanf(n.c_str(), "%lld", &num);
			// printf("%lld\n", num);
			v.push_back( {num==0?1:num, c} );
		} 
		// for(auto i:v) cout << i.X << " " << i.Y << endl;
		for(int i=0; i<v.size(); i++) {
			k -= v[i].X;	
		}

		if(k>=0) {
			for(auto i:v) {
				while(i.X--) cout << i.Y;
			};
			cout << "\n";
		}else cout << "unfeasible\n";
	}
}