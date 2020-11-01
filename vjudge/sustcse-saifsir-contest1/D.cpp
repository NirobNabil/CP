#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define exec(sign, val) for(int i=0; i<n; i++) a[i] = a[i] sign val;
#define swap(x, y) h = a[x]; a[x] = a[y]; a[y] = h;

int main(){
	int t, n, m, h, p, q;
	char c;
	bool r;
	std::vector<int> a;
	scanf("%d", &t);
	for(int ii=1; ii<=t; ii++) {
		r=true;
		a.clear();
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) { scanf("%d", &h); a.push_back( h ); }
		while(m--) {
			cin >> c;
			switch( c ) {
				case 'P':
					scanf("%d %d", &p, &q);
					swap((r?p:a.size()-p-1), (r?q:a.size()-q-1));
					break;
				case 'R':
					r = !r;
					break;
				case 'S':
					scanf("%d", &p);
					exec(+, p)
					break;
				case 'M':
					scanf("%d", &p);
					exec(*, p)
					break;
				case 'D':
					scanf("%d", &p);
					exec(/, p)
					break;
			}
		}
		printf("Case %d:\n", ii);
		for(int i=(r?0:n-1); (r?i<n:i>=0); (r?i++:i--)){ printf("%d", a[i]); if(r?i<n-1:i>0) printf(" "); }
		printf("\n");
	}
}