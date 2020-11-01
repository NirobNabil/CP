#include <bits/stdc++.h>

#define print for(int i=0; i<s_len; i++) cout << calls[i] << " ";

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int s_len, m;
		cin >> s_len >> m;
		string s;
		vector<int> calls(s_len, 0);
		vector<int> presses(26, 0);
		vector<int> p(m);
		cin >> s;
		//cout << s << endl;
		for(int i=0; i<m; i++) cin >> p[i];
		for(int i=0; i<m; i++){
			calls[p[i]-1]++;
		}

		// cout << "calls - ";
		// print
		// cout << endl;

		for(int i=s_len-1; i>0; i--){
			//cout << i << "  " << calls[i-1] << "  " << calls[i] << endl;
			calls[i-1] += calls[i];
		}

		for(int i=0; i<s_len; i++) presses[s[i]-97]++;

		// cout << "calls - ";
		// print
		// cout << endl;

		for(int i=0; i<s_len; i++){
			//cout << s[i]-97 << "  " << calls[i] << endl;
			presses[s[i]-97] += calls[i];
		}

		for(int i=0; i<26; i++) cout << presses[i] << " ";
		cout << endl;
	} 
}