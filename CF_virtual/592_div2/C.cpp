////////  unsolved /////////////
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


#define CEIl(a,b) ((a%b)?a/b+1:a.b)
#define FLOOR(a,b) ((a%b)?a/b-1:a.b)



int main(){
	ll n,p,w,d,ax, ay=-1;
	scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
	while(++ay <= w) {
		if(p == ay*d) goto done;
		else if((p-ay*d)>=0 && (p-ay*d)%w == 0 && (p-ay*d)/w+ay<=n) {
			goto done;
		}
	}
	goto notdone;
	done:
	printf("%lld %lld %lld\n", (p-ay*d)/w, ay, n-(p-ay*d)/w-ay);
	return 0;
	notdone:
	printf("-1\n");
	return 0;
}