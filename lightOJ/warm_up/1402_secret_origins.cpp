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


int main(){
	int i, ix, t, tc=0, n, a[S1];
	scanf("%d", &t);
	while(tc++ < t){
		scanf("%d", &n);
		string tn = bitset<33>(n).to_string();
		int ones = 0;
		for(int i=tn.size()-1; i>0; i--) {
			if(tn[i]=='1') ones++;
			if(tn[i]=='1' && (i==0 || tn[i-1]=='0')) {
				tn[i-1] = '1';
				for(int ix=i; ix<tn.size(); ix++) {
					tn[ix] = ix <= tn.size()-ones ? '0' : '1';
				}
				break;
			}
		}
		printf("Case %d: %d\n", tc, stoi(tn, nullptr, 2));
	}
}