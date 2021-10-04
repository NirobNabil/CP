#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define A(i) (d.find(i)!=d.end()?b[i]:0)

int a[100009];
int b[100009];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, z, k, cmax=0, toLose=0;
		multiset<pair<int, int> > c;
		unordered_multiset<int> d; 
		scanf("%d %d %d", &n, &k, &z);
		k++;
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<k; i++) cmax += a[i];
		// for(int i=1; i<n; i++) b[i] = a[i] + a[i-1];
		for(int i=1; i<k; i++) b[i] = a[i] + a[i-1], c.insert(make_pair(b[i], i));
		// for(auto i=c.rbegin(); i!=c.rend() && z && k>3; i++) {
		// 	printf("(%d,%d) ", (*i).first, (*i).second);
		// }
		// printf("\n");
		for(auto i=c.rbegin(); i!=c.rend() && z && k>3; i++) {
			if( (*i).second < k-2 ){
				// printf("%d\n", cmax);
				toLose = A(k-2) + A(k-3) + a[k-1] + a[k-2];
				if( (*i).first < toLose + a[k-3] - a[k-1] && a[k-3] - a[k-1] > a[k-1] ) {
					cmax += a[k-3];
					cmax -= a[k-1];
					break;
				}
				else if( (*i).first < toLose ) break;
				else {
					cmax += (*i).first;
					cmax -= a[k-1] + a[k-2];
					d.insert( (*i).second );
					k-=2;
					z--;
				}
				// printf("%d %d %d %d\n", (*i).second, cmax, a[k-1], a[k-2]);
			}
		}
		printf("%d\n", cmax);
	}
}