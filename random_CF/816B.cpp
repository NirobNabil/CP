#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 200009
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


int main(){
	int tx, ty, n, k, q;
	multiset<int> start, end;
	scanf("%d %d %d", &n, &k, &q);
	vector<int> v(S1);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &tx, &ty);
		start.insert(tx);  end.insert(ty);
	}
	int tominus=0, curval=0;
	for(int i=0; i<S1; i++) {
		curval -= tominus;
		curval += start.count(i);
		v[i] = curval;
		tominus = end.count(i);
	}
	std::vector<int> cumv(S1);
	for(int i=1; i<S1; i++) {
		cumv[i] = cumv[i-1]+(v[i]>=k);
	}
	while(q--) {
		scanf("%d %d", &tx, &ty);
		printf("%d\n", tx!=0?cumv[ty]-cumv[tx-1]:cumv[ty]);
	}
}