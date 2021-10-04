#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x,a,b, tempA, tempB;
		cin >> n >> x >> tempA >> tempB;
		a = max(tempA,tempB);
		b = min(tempA,tempB);
		//cout << a << " " << b << endl;
		cout << a-b + min(n-a + (b-1), x) << endl;
	}
}