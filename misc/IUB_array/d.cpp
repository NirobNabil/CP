#include <iostream>
#include <string>
// #include <algorithm>
using namespace std;

const int mx = 100000;

char* sort(char *a, int sz) {
	static char b[mx] = {0};
	int cmx = 0;
	for(int i=0; i<sz; i++) {
		for(int ix=0; ix<sz; ix++) {
			if(b[i]<a[ix]) b[i] = a[ix], cmx=ix;
		}
		a[cmx] = -1;
	} 
	for(int i=0; i<sz; i++) {
		a[i] = b[i];
	} 
	return b;	
}

char* chr(string s){
	static char a[mx];
	for(int i=0; i<(int)s.size(); i++) {
		a[i]=s[i];
	}
	sort(a,s.size());
	return a;
} 


int main(){
	string s;
	cout << "Enter the string: ";
	cin >> s;
	char *a = chr(s);
	for(int i=0; i<(int)s.size(); i++) cout << a[i];
}