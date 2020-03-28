#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include "../../utils/utils.cpp"

using namespace std;

struct command{
  char dir;
  int val;
};

struct coordinate{
  int x,y;
};

struct line{
  int a,b,c;
  coordinate start, end;
};

vector<command> parse(string s){
  vector<command> commands;
  char dir;
  string val = "";
  for(int i=0; i<s.length(); i++){
    if(s[i] == ','){
      string::size_type sz;
      //cout << dir << "," << stoi(val, &sz) << endl;
      struct command cmd = {dir, stoi(val, &sz)};
      commands.push_back(cmd);
      val = "";
    }else if(s[i] > 64){
      dir = s[i];
    }else{
      val+=s[i];
    }
  }
  for(int i=0; i<commands.size(); i++){
    cout << commands[i].dir << "  " << commands[i].val << endl;
  }
  return commands;
}



vector<coordinate> check(vector<line> lines, line L){
  vector<coordinate> intersections;
  for(int i=0; i<lines.size(); i++){
    int a = lines[i].a - L.a, b = lines[i].b - L.b, c = lines[i].c - L.c;
    //printf("i=%d b2-4ac=%d \n", i, (b*b)-(4*a*c));
    int a1 = lines[i].a, b1 = lines[i].b, c1 = lines[i].c;
    int a2 = L.a, b2 = L.b, c2 = L.c;
    int x=-1,y=-1;
    // because if L1 and L2 do intersect, both of them cant have a=0 or b=0
    printf("i=%d a1= %d  b1= %d  c1=%d \n",i, a1, b1, c1);
    printf("a2= %d  b2= %d  c2=%d \n", a2, b2, c2);
    if(a1 != a2 || b1 != b2){
      if(a1 == 0 ) y = -c1;
      else x = -c1;
      if(a2 == 0 ) y = -c2;
      else x = -c2;
      cout << "intersect " << x << ", " << y << endl;
      coordinate intsct = {x,y};
      if(   within(intsct.x, lines[i].start.x, lines[i].end.x)
         || within(intsct.y, lines[i].start.y, lines[i].end.y)
         || within(intsct.x, L.start.x, L.end.x)
         || within(intsct.y, L.start.y, L.end.y) ){ cout << "pushed" << endl; intersections.push_back(intsct); }
    }
    cout << endl;
  }
  return intersections;
}

int main(){
    string in;
    vector< vector<command> > commands(2);
    vector< vector<coordinate> > wires(2);
    coordinate starting_point = {0,0};
    wires[0].push_back(starting_point);
    wires[1].push_back(starting_point);
    vector< vector<line> > lines(2);
    for(int i = 0; i<2; i++){
      cin >> in;
      commands[i] = parse(in);
      coordinate current_coo = {0,0};
      cout << "gg2" << endl;
      for(int i2=0; i2<commands[i].size(); i2++){
        cout << "gg" << endl;
        struct coordinate coo = current_coo;
        switch(commands[i][i2].dir){
          case 'U':
            coo.y += commands[i][i2].val;
            break;
          case 'R':
            coo.x += commands[i][i2].val;
            break;
          case 'L':
            coo.x -= commands[i][i2].val;
            break;
          case 'D':
            coo.y -= commands[i][i2].val;
            break;
        }
        wires[i].push_back(coo);
        if(i2 > 0){
          //cout << "came" << endl;
          int a = 0, b=0, c=0;
          //cout << ( wires[i][i2].y - wires[i][i2-1].y ) << endl;
          //cout << ( wires[i][i2].x - wires[i][i2-1].x ) << endl;
          if( wires[i][i2].y - wires[i][i2-1].y == 0 ){
            b = wires[i][i2].y;
            c = wires[i][i2].y;
          }else if( wires[i][i2].x - wires[i][i2-1].x == 0 ){
            a = wires[i][i2].x;
            c=-99999999;
          }
          //int c = 0 - b*wires[i][i2].y - a*wires[i][i2].x;
          struct line L = {a, b, c, wires[i][i2-1], wires[i][i2]};
          lines[i].push_back(L);
        }
        current_coo = coo;
      }
    }
    for(int x=0; x<2; x++){
      cout << "printing " << x << endl;
      for(int i=0; i<lines[x].size(); i++){
        cout << "(" << wires[x][i+1].x << "," << wires[x][i+1].y << "), ";
        cout << lines[x][i].a << "x + " << lines[x][i].b << "y + " << lines[x][i].c << " = 0" << endl;
      }
      cout << endl;
    }

    vector<coordinate> intersects;
    for(int i=0; i<lines.size(); i++){
      for(line L : lines[i]){
        int i_other = (i==1) ? 0 : 1;
        cout << i << "  " << i_other << endl;
        cout << "checking intsct " << L.end.x << ", " << L.end.y << endl;
        vector<coordinate> i_s = check(lines[i_other], L);
        intersects.insert(intersects.end(), i_s.begin(), i_s.end());
      }
    }
    cout << intersects.size() << endl;

    for( coordinate coo : intersects ){
      float dist = sqrt(coo.x*coo.x + coo.y*coo.y);
      cout << "found - " << coo.x << ", " << coo.y << ", " << dist << endl;
    }
    cout << endl;



    return 0;
}
