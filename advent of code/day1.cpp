#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int total = 0;
    cout << "enter stuff" << endl;
    while(1){
        int mass;
        cin >> mass;
        while(1){
            mass /= 3;
            mass = floor(mass);
            mass -= 2;
            if(mass > 0){
                //cout << "fucced up";
                total += mass;
            }
            else{ break; }
        }
        cout << total << endl;
    }
    cout << "gg";
    return 0;
}
