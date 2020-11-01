#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int n;
	scanf("%d", &n);
	int a[2][n], gg;
	map<int, int > d[2];
	unordered_set<int> check[2];
	unordered_map<int, int> subst[2];
	for(int i=0; i<n; i++) scanf("%d", &a[0][i]);
	for(int i=0; i<n; i++) scanf("%d", &a[1][i]);
	sort(a[0], a[0]+n);
	sort(a[1], a[1]+n);
	// for(auto i:a[0]) cout << i << " ";
	// printf("\n");
	// for(auto i:a[1]) cout << i << " ";
	// printf("\n");
	for(int ix=0; ix<2; ix++) {
		for(int i=0; i<n; i++) {
			gg = sqrt(a[ix][i]);
			for(int ii=1; ii<=gg; ii++) {
				if(a[ix][i]%ii == 0) {
					// d[ix][ii].first++;
					subst[ix][a[ix][i]] = -1;
					d[ix][ii] = max(d[ix][ii], a[ix][i]);
					if(ii != a[ix][i]/ii) {
						// d[ix][a[ix][i]/ii].first++;
						d[ix][a[ix][i]/ii] = max(d[ix][a[ix][i]/ii], a[ix][i]);
					}
					if(check[ix].find(ii) != check[ix].end() || check[ix].find(a[ix][i]/ii) != check[ix].end()) {
						// cout << "s - " << ii << " " << a[ix][i]/ii << " " << a[ix][i] << endl;
						subst[ix][ii] = a[ix][i];
						if(ii!=1) subst[ix][a[ix][i]/ii] = a[ix][i];
						break;
					}
					// cout << ix << " " << ii << " - " << d[ix][ii];
					// // for(auto i:d[ix][ii]) cout << i << ",";
					// printf("\n");
				}
			}
			check[ix].insert(a[ix][i]);
		}
	}
	// for(auto i:subst[0]) cout << i.first << " - " << i.second << endl;
	for(auto i=d[0].rbegin(); i!=d[0].rend(); i++){
		if(d[1][(*i).first]>=1) {
			// printf("%d\n", d[0][(*i).first] + d[1][(*i).first] );
			int xd=d[0][(*i).first];
			while(subst[0][xd]!=-1) {
				xd = subst[0][xd];
			}
			int gg=d[1][(*i).first];
			while(subst[1][gg]!=-1) {
				gg = subst[1][gg];
			}
			printf("%d %d\n", gg, xd);
			// printf("%d\n", (*i).second.size());
			// for(auto i:d[0][(*i).first]) cout << i << " ";
			// printf("\n");
			// for(auto i:d[1][(*i).first]) cout << i << " ";
			// printf("\n");
			return 0; 
		}
	}
	// for(auto i:d[0]) cout << i.first <<+ i.second << endl;
}