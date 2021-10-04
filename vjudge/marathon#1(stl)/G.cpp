#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define iit list<pair<char,int> >::iterator
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
	#ifndef DDEBUG
	return;
	#endif
	for(auto i:arr) cout << i << " ";
	printf("\n");
}

struct list_iterator_cmp {
    size_t operator()(const iit &a, const iit &b) const {
        return a->Y < b->Y;
    }
};
int max_=0, min_=INT_MAX, n, op=0, maxop=0;
bool c=0;
list<pair<char,int> > b;
set<iit, list_iterator_cmp > v[2];

iit ia,ib,ip,iq;
int check(iit i) {
	// printf("%d\n", i==b.begin());
	// cout << (bool) << " ";
	i--;
	ia = i;
	i++; i++;
	ib = i;
	i--;
	// printf("a- %c %c %d ", *i, *ib, i!=b.begin() && *i!=*ia);
	// printf("b- %d c- %d\n", (i!=b.begin() && *i!=*ia), (ib!=b.end() && *i!=*ib) );
	if( (i!=b.begin() && i->X!=ia->X) || (ib!=b.end() && i->X!=ib->X) ) return 1;
	else return 0;
}

void add(iit i) {
	// printf("%c %c %c\n", *(--i++), *i, *(++i--) );
	i--;
	ip = i;
	i++; i++;
	iq = i;
	i--;
	// printf("%d %d %d\n", i->Y, ip->Y, iq->Y);
	if(iq!=b.end() && v[!c].find(iq) == v[!c].end() && v[c].find(iq) == v[c].end()){
		// printf("%d %d %d -> ", i->Y, iq->Y, v[!c].find(iq) == v[!c].end());
		v[!c].insert(iq);// printf("add %c %c\n", iq->X, i->X);
	} 
	if(i!=b.begin() && v[!c].find(ip) == v[!c].end() && v[c].find(ip) == v[c].end()) {
		// printf("%d %d %d -> ", i->Y, ip->Y, v[!c].find(ip) == v[!c].end());
		v[!c].insert(ip);// printf("add %c %c\n", ip->X, i->X);
	}
}

int main(){
	int i, ix, t, initial;
	char gg[1000009];
	scanf("%s", gg);
		min_ = INT_MAX, max_ = 0, initial=0, c=0;
		int opx = 0;
		// a = gg;
		n = strlen(gg);
		// cout << a;
		for(int i=0; i<n; i++) {
			b.push_back({gg[i],i});
		}
		// for(auto i=b.begin(); i!=b.end(); i++) {
		// 	cout << &i << endl;
		// }
		for(iit i=b.begin(); i!=b.end(); i++) {
			if(check(i)) v[c].insert(i);
		}
		// for(auto i:v[c]) printf("%c ", i->X);
		// printf("\n");
		// for(auto i:v[c]) printf("%d ", i->Y);
		// printf("\n");
		// for(auto i:v[c]) cout << *i << endl;
		int topx=0;
		unordered_set<int> xx;
		// for(auto i:b) printf("%c", i.X,i.Y);
		// printf("\n");
		while(!v[c].empty()) {
			xx.clear();
			for(auto i:v[c]) {
				if(check(i)) add(i), xx.insert(i->Y), topx=1;
			}
			// printf("sw\n");
			for(auto i:v[c]) {
				if(xx.find(i->Y)!=xx.end()) b.erase(i); //printf("%d ", i->Y);
			}
			opx+=topx;
			// printf("\n");
			// for(auto i:v[!c]) {
			// 	if(check(i)) printf("%d ", i->Y);
			// }
			// printf("\n");
			// printf("%d %d\n", opx, topx);
			// for(auto i:b) printf("%c%d", i.X,i.Y);
			// printf("\n");
			v[c].clear();
			c = !c;
			topx=0;
			// v[c].erase(v[c].begin());
			// if(v[c].size()==0) c != c, opx++, printf("sw\n");;
		}
		printf("%d\n", opx);
}