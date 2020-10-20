#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define BACK if(q.size()) cout << q.back() << "\n", q.pop_back(); else cout << "No job for Ada?" << "\n";
#define FRONT if(q.size()) cout << q.front() << "\n", q.pop_front(); else cout << "No job for Ada?" << "\n";
#define PUSH_BACK cin >> temp, q.push_back(temp);
#define PUSH_FRONT cin >> temp, q.push_front(temp);

int main(){
	int t, temp;
	bool r=true;
	scanf("%d", &t);
	string c;
	deque<int> q;
	while(t--){
		cin >> c;
		if( r ){
			if(c=="back") BACK
			else if(c=="front") FRONT
			else if(c=="push_back") PUSH_BACK
			else if(c=="toFront") PUSH_FRONT
		}else {
			if(c=="back") FRONT
			else if(c=="front") BACK
			else if(c=="push_back") PUSH_FRONT
			else if(c=="toFront") PUSH_BACK
		}
		if(c=="reverse") r = !r;
	}
}