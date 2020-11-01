#include <iostream>

using namespace std;

void print(bool bits[], int len){
	for(int i=1; i<=len; i++) cout << bits[i];
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		bool bits[n+1] = {0};
		while(q--){
			char c;
			int i, j;
			cin >> c >> i;
			if(c == 'I'){
				cin >> z;
				for(; j>=i; j--) bits[j] = !bits[j];
			}
			print(bits, n+1);
		}
	}
}