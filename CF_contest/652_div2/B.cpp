#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		char s[n];
		scanf("%s", &s);
		list<char> str(s, s+n);
		// int last1=n+1, first1, last0, next0=n+1, i=-1;
		char cur_streak = '1';
		// while(s[++i] != '1') continue;
		// first1 = last1 = i;
		// for(; i<n; i++) {
		// 	if(cur_streak=='1' && s[i]=='0'){
		// 		for(i=last1+1; s[i]!='0'; i++) s[i]='C';
		// 		i++; 
		// 		for(; i<n && s[i]!='1'; i++) s[i]='C';
		// 		last1=i;
		// 	}
		// }
		list<char>::iterator last1, first1, last0, next0, i;
		for(i = str.begin(); i != str.end() && *i !='1'; i++) cout << "g" << *i << " ";
		first1 = last1 = i;
		cout << *last1 << endl;
		for(; i != str.end(); i++) {
			if(cur_streak=='1' && *i=='0'){
				for(i=++last1; *i!='0';) i = str.erase(i);
			 	// str.erase(++last1, ++i);
				i++; 
				for(; i != str.end() && *i!='1';) i = str.erase(i);
				last1=i;
			}
			cout << "x" << *i << endl;
			// i = str.erase(i);
		}
		for(i=first1; i!=str.end(); i++) {
			if(*i == '1' && (++++i)---- != str.end() && (++i)-- == '0') 
		}
		// for(int i=0; i<n; i++) {
		// 	if(s[i] != 'C') printf("%c", s[i]);
		// }
		for(auto i : str){
			cout << i;
		}
		printf("\n");
	}
}