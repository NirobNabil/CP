#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define line cout<<"--------------------------"<<endl
#define dd(x) cout<<#x<<" = "<<x<<' '
#define sz(v) (ll)v.size()
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define all(v) v.begin(),v.end()
#define pb push_back
#define pi acos(-1)
#define ff first
#define ss second
#define mp make_pair
#define mod 10056 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx=100009; 
typedef pair<int,int> pii ; 
vector<pii>suru[mx],ses[mx]; 
int main()
{
    fast; 
     int t; cin>>t; 
     while(t--)
     {
         int n,q; 
         cin>>n>>q; 
         for(int i=0;i<=n+1;i++) suru[i].clear(),ses[i].clear();
         for(int i=0;i<q;i++)
         {
             int l,r,val;
             cin>>l>>r>>val; 
             suru[l].pb({i,val});
             ses[r+1].pb({i,val});
         }
         set<pii> s; 
         int bad=0;
         for(int i=1;i<=n;i++)
         {
            for(auto x: ses[i])
            {
                auto it=s.lower_bound(x);
                int pre=0,post=1e8; 
                if(it!=s.begin())
                {
                    auto a=it; 
                    a--; 
                    pre=a->ss; 
                }
                auto a=it;
                a++; 
                if(a!=s.end()) post=a->ss; 
                if(pre>=x.ss) bad--; 
                if(x.ss>=post) bad--;  
                if(pre>=post) bad++;
                s.erase(x);
            }
            for(auto x: suru[i])
            {
                s.insert(x);
                auto it=s.lower_bound(x);
                int pre=0,post=1e8; 
                if(it!=s.begin())
                {
                    auto a=it; 
                    a--; 
                    pre=a->ss; 
                }
                auto a=it;
                a++; 
                if(a!=s.end()) post=a->ss; 
                if(pre>=x.ss) bad++; 
                if(x.ss>=post) bad++; 
                if(pre>=post) bad--; 
            }
            cout<<!(bool)bad; 
         }
         cout<<endl; 
         
     }
}
