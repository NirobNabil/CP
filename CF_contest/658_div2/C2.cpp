#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, flag=0;
vector<int> is;
deque<int> a,b;

int val(int i){
	if(i){
		return flag?!a.front():a.back();
	}else return flag?!a.back():a.front();
}

// 01011  
// 11011  11011
// 11011  

void flip(int i){
	if(!i) {
		is.push_back(1);
		if(flag) a[a.size()-1] = !a[a.size()-1];
		else a[0] = !a[0];
		return;
	}
	is.push_back(a.size());
	flag=!flag;
	// printf("flipped %d\n", flag);
}

int main(){
	int t;
	char as[100005], bs[100005];
	scanf("%d", &t);
	while(t--){
		flag=0;
		is.clear();
		scanf("%d", &n);
		scanf("%s", &as);
		scanf("%s", &bs);
		a.clear();
		b.clear();
		for(int i=0; i<n; i++) a.push_back( (as[i]=='1')?1:0);
		for(int i=0; i<n; i++) b.push_back( (bs[i]=='1')?1:0);
		for(int i=n-1; i>=0; i--,flag?a.pop_front():a.pop_back()) {
			// printf("f-%d - ", flag);
			// for(auto i:a) cout<< (flag?!i:i);
			// printf("\n");
			// printf("%d %d\n", val(0), val(1));
			if(val(1)==b[i]) {
				
			}else if(val(0)!=b[i]) {
				flip(i);
			}else if(val(0)==b[i]) {
				flip(0);
				flip(i);
			}
		}
		printf("%d ", is.size());
		for(auto i:is) printf("%d ", i);
		printf("\n");
	}
}