#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define vp vector<pair<int,int> >
int i, ix, t, n;
std::vector<int> v(4);
int corners[4];

int san(int x) {
	if(x<0) x=(x-2)*-1;
	x = x%4;
	return x;
}

void pr() {
	for(auto i:corners) cout << i << " ";
	cout << endl;
}

int check(int i) {
	int pstate;
	if(i>3) return 1;
	if(v[i]==1) {
		if(v[san(i+1)]!=-1) {
			pstate=corners[i];
			corners[i]=1;
			// if(i==2) pr();
			if(check(i+1)) return 1;
			corners[i]=pstate;
		}
		if(v[san(i-1)]!=-1) {
			pstate=corners[san(i-1)];
			corners[san(i-1)]=1;
			// if(i==2) pr();
			if(check(i+1)) return 1;
			corners[san(i-1)]=pstate;
		}
		return 0;
	}else if(v[i]==2){
		// printf("came %d %d-%d\n", i, san(i+1), san(i-1));
		if(v[san(i+1)]!=-1 && v[san(i-1)]!=-1){
			corners[san(i)]=1; 
			corners[san(i-1)]=1;
			// if(i==2) pr();
			return check(i+1);
		}
		return 0;
	}else return check(i+1);
}

int check2(int i) {
	int pstate;
	if(i>3) return 1;
	if(v[i]==1) {
		// pr();
		// printf("xd %d\n", i);
		if(corners[i] ^ corners[san(i-1)]) return check2(i+1);
		else if(corners[i] && corners[san(i-1)]) return 0;
		else {
			if(v[san(i+1)]==2 || (!corners[san(i+1)] && v[san(i+1)]!=-1)) {
		// printf("xd %d\n", i);
				pstate=corners[i];
				corners[i]=1;
				// if(i==2) pr();
				if(check2(i+1)) return 1;
				corners[i]=pstate;
			}
			if(!corners[san(i-2)] && v[san(i-1)]!=-1) {
		// printf("xd %d\n", i);
				pstate=corners[san(i-1)];
				corners[san(i-1)]=1;
				// if(i==2) pr();
				if(check2(i+1)) return 1;
				corners[san(i-1)]=pstate;
			}
		}
		// printf("gg %d\n", i);
		return 0;
	}else if(v[i]==2){
		// printf("came %d %d-%d\n", i, san(i+1), san(i-1));
		if(v[san(i+1)]!=-1 && v[san(i-1)]!=-1 &&
			!(v[san(i+1)]==1 && corners[san(i+1)]==1) &&
			!(v[san(i-1)]==1 && corners[san(i-2)]==1) ){
			corners[san(i)]=1; 
			corners[san(i-1)]=1;
			// if(i==2) pr();
			return check2(i+1);
		}
		return 0;
	}else return check2(i+1);
}



int main(){
	scanf("%d", &t);
	while(t--){
		memset(corners, 0, sizeof(corners));
		// v.clear();
		int possible = true;
		scanf("%d", &n);
		for(int i=0; i<4; i++) scanf("%d", &ix), v[i]=ix;	
		// int corners[4][4];
		// for(int i=0; i<4; i++) {
		// 	for(int ix=0; ix<4; ix++) corners[i][ix] = 0; 
		// }

		for(int i=0; i<4; i++) {
			if(v[i]==0) {
				v[i]=-1;
				continue;
			}
			if(n-v[i]<0) possible=false;
			if(n-v[i]>2) v[i]=0;
			else v[i] = 2-(n-v[i]);
		}

		// for(auto i:v) {
		// 	printf("%d ", i);
		// }
		
		// printf("\n");
		if(n==2) printf("%s\n", check2(0) && possible?"YES":"NO");
		else printf("%s\n", check(0) && possible?"YES":"NO");
 	}
}