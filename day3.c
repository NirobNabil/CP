#include <stdio.h>
#include <string.h>
#include <vector.h>
//#include "../../utils/utils.cpp"

struct command{
  int dir, val;
};

string parse(string s){
  vector<command> commands;
  int dir = -1;
  string num;
  for(int i=0; i<s.length; i++){
    if(dir != -1){
      struct command cmd = {dir, stoi()};
    }
    switch(s[i]){
      case 'U':
        nextDir = 0;
        break;
      case 'R':
        nextDir = 1;
        break;
      case 'L':
        nextDir = 2;
        break;
      case 'D':
        nextDir = 3;
        break;
    }
  }
}

int main(){

}

