#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<ll,ll>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const ll base[] = { 10, 10 };
const ll primes[] = { 1000000000+7, 1000000000+9 };
ll POW[2][1000] = { {1}, {1} };


pp get_hash(string s) {
	
	ll hash[2] = {0,0};
	for(int i=0; i<s.length(); i++) 
		for(int q=0; q<2; q++)  
			hash[q] = ( hash[q] + (s[i]-'a'+1) * POW[q][s.length()-i-1] ) % primes[q];
	
	return {hash[0], hash[1]};
}


pp get_next_hash(string &s, int l, int r, pp hash, int sz) {
	
	ll t_hash[] = { hash.X, hash.Y };
	for(int q=0; q<2; q++) {
		t_hash[q] -= ( (s[l]-'a'+1) * POW[q][sz-1] ) % primes[q];
		t_hash[q] = ( t_hash[q] * base[q] ) % primes[q];
		t_hash[q] += (s[r+1]-'a'+1);
	} 
	
	return {t_hash[0], t_hash[1]};
}

bool linear_match(string s1, string s2) {
	// to be implemented
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string t, s;
	cin >> t >> s;

	for(ll i=1; i<s.length(); i++) {
		POW[0][i] = (POW[0][i-1]*base[0]) % primes[0];
		POW[1][i] = (POW[1][i-1]*base[1]) % primes[1];
	} 


	auto hash = get_hash(s);

	auto t_hash = get_hash(t.substr(0, s.length()));
	int l = 0, r = s.length()-1;
	
	for(int i=0; i<t.length(); i++) {
		if(	t_hash.X == hash.X 
			&& t_hash.X == hash.X
			&& linear_match(s, t.substr(i, s.length()))
		) {
			cout << "Match found at " << i << "\n";
			return 0;
		} else if(i != t.length()-1) {
			t_hash = get_next_hash( t, l, r, t_hash, s.length() );
		}
		l++; r++;
	} 

	cout << "Match not found\n";

}