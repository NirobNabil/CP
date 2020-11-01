#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d\n", &t);
	while(t--){
		string in;
		getline(cin, in);
		// cout << in;
		bool found_word = false;
		int words = 0;
		for(int i=0; i<in.size(); i++){
			if( (in[i]>64 && in[i]<91) || (in[i]>96 && in[i]<123)) found_word = true;
			if(in[i] == 32 && found_word) words++, found_word = false; 
		}
		cout << words+1 << "\n";
	}
}