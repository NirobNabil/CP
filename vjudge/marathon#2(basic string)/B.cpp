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

int main()
{
    ll f=1,i=1,j,k,l;
    string s;
    while( f )
    {
        cin>>s;
        if(s=="*") f=0;
        else if(s=="Hajj") cout<<"Case "<<i<<": Hajj-e-Akbar\n";
        else cout<<"Case "<<i<<": Hajj-e-Asghar\n";
        i++;
    }
    return 0;
}