#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int n;
	cin >> n;
	int a[n];
	vector<int> b;
	cin >> a[0];
	for(int i=1; i<n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	int t,x,y,z, s_i=0;
	cin >> t;
	while(t--){
		cin >> x;
		if(x==1){
			cin >> y >> z;
			z -= s_i+1;
			y -= s_i+1;
			if(y==0) cout << a[z] << endl;
			else if(y<0 && z>=0) {
				cout << a[z] + b[(y+1)*-1] << endl;
			}else if(y<0 && z<0){
				cout << b[(y+1)*-1] - ((z+2<=0)?b[(z+2)*-1]:0) << endl;
			}else cout << a[z] - a[y-1] << endl;
		}
		else {
			cin >> y;
			if(b.size()>0) b.push_back(y+*(b.rbegin()));
			else b.push_back(y);
			s_i++;
		}
	} 
	return 0;
}