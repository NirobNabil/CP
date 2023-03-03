#include <bits/stdc++.h>
using namespace std;

vector<int> h = {-1};

void heapify( vector<int> x ) {

	for(auto i:x) h.push_back(i);

	for(int i=h.size()-1; i>0; i--) {
		if( i*2 < h.size() && h[i*2] < h[i] ) {
			swap(h[i], h[i*2]);
		}
		if( i*2+1 < h.size() && h[i*2+1] < h[i] ) {
			swap(h[i], h[i*2+1]);
		}
	} 
}

int pop() {
	swap(h[1], h[h.size()-1]);
	int r = h.back(), i = 1;
	h.pop_back();
	while(i < h.size()) {
		if( i*2 < h.size() && h[i*2] < h[i] ) { 
			swap(h[i], h[i*2]);
			i = i*2;
		} else if( i*2+1 < h.size() && h[i*2+1] < h[i] ) { 
			swap(h[i], h[i*2+1]);
			i = i*2+1;
		} else break;
	}
	return r;
}	



void insert(int x) {
	h.push_back(x);
	int i = h.size()-1;
	while(i>1) {
		if( h[i] < h[i/2] ) swap(h[i], h[i/2]), i = i/2;
	}
}



int main(){
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; i++) {
	    	cin >> a[i];
	    }
	    for(int i=0; i<n; i++) {  
	    	insert(a[i]);
	    }
	    for(int i=0; i<n; i++) {
	    	cout << pop() << endl;
	    }
	}
}