#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define X first
#define Y second

bool pair_check(char x, char y){
  return (x+y==153 || x+y==158)?true:false;
}

bool axis_check2(char x, char y) {
  return (x+y==153)?true:false; //true=v false=h
}

bool axis_check(char x){
  return (x==68 || x==85)?true:false;
}

char lc;
unordered_map<char, int> j, bias;
vector<pair<int, char> > g;

void do1(int a,int b, int c){
  bool r=true;
  if(bias[g[a].Y]>bias[g[c].Y]) r=false;
  while(g[0].X > g[3].X) {
    printf("%c%c%c", (r?g[a].Y:g[c].Y), g[b].Y, (r?g[c].Y:g[a].Y));
    lc=g[2].Y;
    g[0].X--;
    bias[g[c].Y]++; bias[g[b].Y]++; bias[g[a].Y]++;
    r=!r;
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    lc = 'U';
    int n;
    scanf("%d", &n);
    char a[n];
    scanf("%s", a);
    j.clear();
    g.clear();
    j['U']=j['D']=j['L']=j['R']=bias['U']=bias['D']=bias['L']=bias['R']=0;
    bias.clear();
    for(int i=0; i<n; i++) {
      j[a[i]]++;
    }
    for(auto i:j) g.push_back(make_pair(i.second, i.first));
    sort(g.begin(),g.end());
    reverse(g.begin(), g.end());
    int x=0;
    for(auto i:g) {
      printf("%c%d, ", i.second, i.first);
    }
    printf("\n");
    if(g[1].first==0) {
      while(g[0].first--) printf("%c", g[0].second);
      printf("\n");
      continue;
    }
    if(g[0].X != g[1].X || g[0].X != g[2].X) {
      // printf("in\n");
      if(pair_check(g[0].Y,g[1].Y)){
        if(g[1].X != g[2].X) {
          printf("Impossible\n");
          continue;
        }else {
          while(g[0].X > g[2].X ) printf("%c", g[0].Y), g[0].X--, lc=g[0].Y, bias[g[0].Y]++;
        }
      }else if(!pair_check(g[0].Y,g[2].Y)){
        while(g[1].X > g[2].X ) printf("%c", g[1].Y), g[1].X--, lc=g[1].Y, bias[g[1].Y]++;
        while(g[0].X > g[2].X ) printf("%c", g[0].Y), g[0].X--, lc=g[0].Y, bias[g[0].Y]++;
      }else {
        while(g[0].X > g[2].X ) printf("%c", g[0].Y), g[0].X--, lc=g[0].Y, bias[g[0].Y]++;
        while(g[1].X > g[2].X ) printf("%c", g[1].Y), g[1].X--, lc=g[1].Y, bias[g[1].Y]++;
      }
    }
    if(g[2].X != g[3].X) {
      if(pair_check(g[0].Y,g[2].Y)) do1(0,1,2);
      else if(pair_check(g[0].Y,g[1].Y)) do1(0,2,1);
      else do1(1,0,2);
    }
    while(g[0].X-- >0){
      if(axis_check(lc)){
        printf("%c%c%c%c", bias['R']>bias['L']?'L':'R', bias['U']>bias['D']?'D':'U', bias['R']>bias['L']?'R':'L', bias['U']>bias['D']?'U':'D');
      }else printf("%c%c%c%c", bias['U']>bias['D']?'D':'U', bias['R']>bias['L']?'L':'R', bias['R']>bias['L']?'R':'L', bias['U']>bias['D']?'U':'D');
    }
    printf("\n");
  }
}