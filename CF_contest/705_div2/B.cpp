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

int mh, mm, h, m;
vector<int> a = {0,1,2,5,8}, r = {0,1,5,2,8};
map<int,int> mapr;
vector<char> ac = {'0', '1', '2', '5', '8'};
vector<string> v;
unordered_map<string, string> vr;
int i, ix, t, n;

  
  
// This code is contributed by rathbhupendra 

bool valid(string s) {
	int h, m;
	
	h = (s[0]-'0')*10 + s[1]-'0';  
	m = (s[2]-'0')*10 + s[3]-'0';  
	if(h>=mh || m>=mm) return false;

	char r[] = "0000";
	r[0] = mapr[s[3]-'0'] + '0'; 
	r[1] = mapr[s[2]-'0'] + '0'; 
	r[2] = mapr[s[1]-'0'] + '0'; 
	r[3] = mapr[s[0]-'0'] + '0'; 
	h = (r[0]-'0')*10 + r[1]-'0';  
	m = (r[2]-'0')*10 + r[3]-'0';  
	if(h<mh && m<mm) return true;
	else return false;
}

int main(){
	scanf("%d", &t);
	for(int i=0; i<a.size(); i++) {
    mapr[a[i]] = r[i];
  } 
  string s = "0000";
  for(auto i1:ac) {
  	for(auto i2:ac) {
  		for(auto i3:ac) {
  			for(auto i4:ac) {
  				s = "";
  				s += i1;
  				s += i2;
  				s += i3;
  				s += i4;
  				v.pb(s);
  			}
  		}
  	}
  } 

  // for(auto i:v) {
  // 	cout << i << endl;
  // }

	while(t--){
		scanf("%d %d", &mh, &mm);
		cin >> s;
		sscanf(s.c_str(), "%d:%d", &h, &m);		
		char q[5];
		sprintf(q, "%02d%02d", h,m);
		// printf("%s\n", q);
		auto it = lower_bound(v.A(), v.B(), q);
		for(; it!=v.end(); it++) {
			if(valid(*it)) {
				string ans = *it;
				printf("%c%c:%c%c\n", ans[0], ans[1], ans[2], ans[3]);
				break;
			}
		}
		if(it==v.end()) printf("00:00\n");
	}
}x`x`