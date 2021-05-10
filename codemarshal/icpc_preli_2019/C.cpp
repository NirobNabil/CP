#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

struct team
{
	int sol, sub, pen;
	vector<int> sub_times; 	
};


pair<int,int> get_pen(int mn_sol, int id, vector<team> &teams) {

	int pen = teams[id].sub_times[0];
	int sol = teams[id].sol;
	int i = 0;
	while(sol+i <= mn_sol && i < teams[id].sub_times.size()) {
		pen += teams[id].sub_times[i++];
	}
	printf("%d %d %d %d\n", id, mn_sol, pen, sol+i);
	return {pen, sol+i};
}


int solve(vector<team> &teams, vector<int> &ranks) {

	int mn_sol = teams[ranks.back()].sol, mx_pen = teams[ranks.back()].pen;
  for(int i=ranks.size()-2; i>=0; i--) {
  	pair<int,int> gg = get_pen(mn_sol, ranks[i], teams);
  	int c_pen = gg.X;
  	int c_sol = gg.Y;
  	if(c_sol > mn_sol) {
  		mn_sol = c_sol;
  		mx_pen = c_pen;
  	}else if(c_sol == mn_sol) {
  		if(c_pen > mx_pen) {
  			gg = get_pen(++mn_sol, ranks[i], teams);
  			c_pen == 
  		}
  	}

  } 
  return 1;
}


int main(){
	int i, ix, t, n, x, y, z, zz, p;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<team> teams(n+1);	
		for(int i=0; i<n; i++) {
      scanf("%d %d %d %d", &x, &y, &z, &p);
	    // cerr << p << endl;
      teams[x].sol = y;
    	teams[x].pen = z;
      for(int ix=0; ix<p; ix++) {
      	scanf("%d", &zz);
      	teams[x].sub_times.pb(zz);
      } 
    }
    vector<int> ranks(n);
    for(auto &gg:ranks) {
    	cin >> gg;
    }
    cout << solve(teams, ranks) << endl;
	}
}
