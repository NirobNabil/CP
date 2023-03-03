#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	stack<char> s;
	char in[100005];
	scanf("%s", in);
	int l = strlen(in), x=0;
	for(int i=0; i<l; i++) {
		if(!s.empty() && s.top()==in[i]) { s.pop(); x++; continue; }
		s.push(in[i]);
	} 
	printf("%s\n", x%2==0?"No":"Yes" );
}