#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

bool pair_check(char x, char y){
  return (x+y==153 || x+y==158)?true:false;
}

int main(){
  int t;
  scanf("%d", &t);
  unordered_map<char, int> j;
  while(t--){
    char lc='U';
    int n;
    scanf("%d", &n);
    char a[n];
    scanf("%s", a);
    j.clear();
    j['U']=j['D']=j['L']=j['R']=0;
    for(int i=0; i<n; i++) {
      j[a[i]]++;
    }
    vector<pair<int, char> > g;
    for(auto i:j) g.push_back(make_pair(i.second, i.first));
    sort(g.begin(),g.end());
    reverse(g.begin(), g.end());
    int x=0;
    // for(auto i:g) {
    //   printf("%c%d, ", i.second, i.first);
    // }
    // printf("\n");
    if(g[1].first==0) {
      while(g[0].first--) printf("%c", g[0].second);
      printf("\n");
      continue;
    }
    if(g[0].X != g[1].X || g[0].X != g[2].X) {
      // printf("in\n");
      if(pair_check(g[0].Y,g[1].Y) && g[1].X != g[2].X){
        printf("Impossible\n");
        continue;
      }
      if(!pair_check(g[0].Y,g[2].Y)){
        while(g[1].X > g[2].X ) printf("%c", g[1].Y), g[1].X--, lc=g[1].Y;
        while(g[0].X > g[2].X ) printf("%c", g[0].Y), g[0].X--, lc=g[0].Y;
      }else {
        while(g[0].X > g[2].X ) printf("%c", g[0].Y), g[0].X--, lc=g[0].Y;
        while(g[1].X > g[2].X ) printf("%c", g[1].Y), g[1].X--, lc=g[1].Y;
      }
    }
    // for(auto i:g) {
    //   printf("%c%d, ", i.second, i.first);
    // }
    // printf("\n");
    // x=5;
    if(g[2].X != g[3].X) {
      if(pair_check(g[0].Y,g[2].Y)){
        while(g[0].X-- >g[3].X) {
          printf("%c%c%c", g[0].Y, g[1].Y, g[2].Y);
          lc=g[2].Y;
          // g[0].X--; //g[1].X--; g[2].X--;
        }
      }else {
        while(g[0].X-- >g[3].X) {
          printf("%c%c%c", g[0].Y, g[2].Y, g[1].Y);
          lc=g[1].Y;
        }

        // g[0].X--; //g[1].X--;g[2].X--;
      } 
    }
    // for(auto i:g) {
    //   printf("%c%d, ", i.second, i.first);
    // }
    // printf("\n");
    // x=5;
    if(lc!='D') while(g[0].X-- > 0) printf("URDL");
    else while(g[0].X-- > 0) printf("DRUL");
    printf("\n");
  }
}