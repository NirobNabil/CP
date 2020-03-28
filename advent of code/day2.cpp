#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "../../utils/utils.cpp"

using namespace std;

int main(){
    string input;
    cin >> input;
    vector<int> nums;
    for(short int i=0, tempI = 0; i<input.length(); i++){
        if(input[i] == ','){
            int gg = stoi(input.substr(tempI, i-tempI));
            //cout << gg << ",";
            tempI = ++i;
            nums.push_back(gg);
        }
    }
    nums[1] = 12;
    nums[2] = 2;
    for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
        cout << *i << ",";
    }
    cout << "\n \n";
    for(int i = 0; i < nums.size(); i+=4){
        if(nums[i] == 1){
            nums[nums[i+3]] = nums[nums[i+2]] + nums[nums[i+1]];
        }else if(nums[i] == 2){
            nums[nums[i+3]] = nums[nums[i+2]] * nums[nums[i+1]];
        }else if(nums[i] == 99){
            cout << "halt" << endl;
            break;
        }
        printVector<vector<int>>(nums, i, i+4);
    }
    printVector<vector<int>>(nums);
}
