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
#define CEIL(a,b) ( (a)%(b) ? (a)/(b)+1 : (a)/(b) )

std::vector<int > ml(S1+9);

int main(){

	int tc;
	scanf("%d", &tc);
  std::vector<int > tcl;
  map<int,int> b;
  set<int> index;
  vector<pair<int,int> > bl;

	for(int t=1; t<=tc; t++) {
		int i, ix, n, x, y, m;
    scanf("%d %d", &n, &m);
    index.clear();
    bl.clear();
    b.clear();
    fill(ml.A(), ml.B(), 0);

    for(int i=0; i<n; i++)  {
      scanf("%d %d", &x, &y);
      b[x] = max(b[x], y);
    }

    for(auto i:b) bl.push_back({i.Y, i.X});

    sort(bl.A(), bl.B());

    int d, mod;
    for(int i=m; i>=1; i--) index.insert(i); 
   	while(index.size() && bl.size()) {

			for(auto i=index.begin(); i!=index.end();) {
				d = (*i / bl.back().Y);
				mod = (*i % bl.back().Y);
				if( ( d % 2 == 1 && mod == 0 ) || ( d % 2 == 0 && mod != 0 ) ) {
					ml[*i] = bl.back().X;
					tcl.pb(*i);
					i++;
				} else {
					i = index.find(CEIL(*i, bl.back().Y)*bl.back().Y +1);
				}
			}

			for(auto i:tcl) index.erase(i);
			tcl.clear();
			bl.pop_back();
		}

		printf("Case #%d: ", t);
		for(int i=1; i<=m; i++) printf("%d%c", ml[i], " \n"[i==m]);

	} 
	return 0;
}