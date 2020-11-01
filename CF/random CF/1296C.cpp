#include <iostream> 
#include <set>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

typedef pair <int,int> coordinate;
typedef pair <coordinate, bool> coodinate_map_pair;

int back_check(coordinate *coos, int curr_i, coordinate curr_co, int smallest){
  for(int i=curr_i-1; i>=0; i--){
    //cout << "L11 coos[curr_i] = " << curr_co.first << "," << curr_co.second << endl;
    //cout << "L12 coos[i] = " << coos[i].first << "," << coos[i].second << endl;
    if(curr_co == coos[i] && curr_i-i < smallest) return i+1;
  }
  return -1;
}

string to_str(coordinate coo){
  return to_string(coo.first) + "," + to_string(coo.second);
}

void print_coos(coordinate *coos, int n){
  for(int i=0; i<n; i++) cout << coos[i].first << "," << coos[i].second << " ";
  cout << endl;
}

struct hash_pair { 
  template <class T1, class T2> 
  size_t operator()(const pair<T1, T2>& p) const
  { 
      auto hash1 = hash<T1>{}(p.first); 
      auto hash2 = hash<T2>{}(p.second); 
      return hash1 ^ hash2; 
  } 
}; 

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, l=-1, r=-1;
    cin >> n;
    int smallest = 999999;
    char dirs[n];
    string in;
    cin >> in;
    for(int i=0; i<n; i++) dirs[i] = in[i];
    //for(int i=0; i<n; i++) cout << dirs[i] << ",";
    coordinate coos[n+1], curr_co(0,0);

    unordered_map <coordinate, int, hash_pair> coos_map;
    unordered_set <coordinate, hash_pair> coos_hash;
    //inserting the curr_co of last loop and will skip the last curr_co
    //coos_hash.insert(curr_co);
    //coodinate_map_pair curr_co_map(curr_co, true);
    coos_map.emplace(curr_co, 0);
    coos[0] = curr_co;
    for(int i=1; i<=n; i++){
      switch(dirs[i-1]){
        case 'L':
          curr_co.first -= 1;
          break;
        case 'R':
          curr_co.first += 1;
          break;
        case 'U':
          curr_co.second += 1;
          break;
        case 'D':
          curr_co.second -= 1;
          break;
      }
      //cout << +"curr_co" << curr_co.first << "," << curr_co.second << endl;
      //print_coos(coos, i);
      if(coos_map.find(curr_co) != coos_map.end()){
        //assuming if the count func doesnt return -1 back_check will also not return -1
        //int xd = back_check(coos, i, curr_co, smallest);
        int xd, nowl, nowr;
        if(coos_map.find(curr_co) != coos_map.end()) xd = coos_map[curr_co];
        else xd = -1;
        //cout << "L54 " << curr_co.first << "," << curr_co.second << "  " << smallest << "  " << xd << endl;
        nowl = (xd>=0)? xd + 1 : nowl;
        nowr = (xd>=0)? i : nowr;
        if(smallest > nowr - nowl) l = nowl, r = nowr, smallest = r-l;
      }
      //coos_hash.insert(curr_co);
      if(coos_map.find(curr_co) == coos_map.end()) coos_map.emplace(curr_co, i);
      else coos_map[curr_co] = i;
      coos[i] = curr_co;
    }
    if(l!=-1 && r!=-1) cout << l << " " << r << endl;
    else cout << -1 << endl;
  }
}