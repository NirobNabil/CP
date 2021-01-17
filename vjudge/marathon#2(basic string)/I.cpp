#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

void pv(){ printf("\n"); }

template<typename T, typename... Args>
void pv(T a, Args... args) {
	#ifndef DDEBUG
	return;
	#endif
	std::cout << a << " "; pv(args...);
}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	#ifndef DDEBUG
	return;
	#endif
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

template<typename T>
void parr(T arr) {
	#ifndef DDDEBUG
	return;
	#endif
	for(auto i:arr) cout << i << " ";
	printf("\n");
}

vector<int> chksubstr(string a, string b){
	std::vector<int> v;
	for(int i=0; i<a.length()-1; i++) {
		if(a[i]==b[0] && a[i+1]==b[1]) v.push_back(i);
	} 
	return v;
}

int main(){
	string a;
	cin >> a;
	std::vector<int> p = chksubstr(a,"AB");
	std::vector<int> q = chksubstr(a,"BA");
	// // if(  ( x.size()==0 || y.size()==0)
	// // 	|| ( x.size()==1 && y.size()==1
	// // 		 && ( find(y.begin(),y.end(),x[0]+1)!=y.end()
	// // 	      ||find(y.begin(),y.end(),x[0]-1)!=y.end() ) ) )	 printf("NO\n");
	// // else {
	// // 	printf("YES\n");
	// // }
	int xA=0, xB=0,yA=0,yB=0;
	for(int i=0; i<a.length()-1; i++) {
		if(a[i]=='A' && a[i+1]=='B') {
			if( (i+2<a.length() && a[i+2]=='A') ) xA=1;
			if( (i-1>=0 && a[i-1]!='B') ) xB=1;
		}
	}
	for(int i=0; i<a.length()-1; i++) {
		if(a[i]=='B' && a[i+1]=='A') {
			if( (i+2<a.length() && a[i+2]=='B') ) yA=1;
			if( (i-1>=0 && a[i-1]!='A') ) yB=1;
		}
	}
	
	if( ((x==1 || p.size()>1) && q.size()>0) || ((y==1 || q.size()>1) && p.size()>0)) printf("YES\n");
	else printf("NO\n");
	return 0;
}