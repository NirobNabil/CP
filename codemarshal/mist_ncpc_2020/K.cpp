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
	int i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> a(n);`
		for(auto &i: a) 
			scanf("%d", &i);
		int mx = *max_element(a.A(), a.B()), c=0;
		for(auto i:a)
			if(i == mx) c++;
		printf("%s\n", c==1?"Yes":"No");
	}
}