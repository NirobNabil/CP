#include<bits/stdc++.h>
using namespace std;

int calc(string s) {
    int mx = 0, x = 0, y = 0;

    vector<string> v = {"LR", "RL", "DU", "UD"};
    for(string s2 : v) if(s.find(s2) != string::npos) return 1e9;

    for(char c : s) {
        if(c == 'U') y++; if(c == 'D') y--;
        if(c == 'R') x++; if(c == 'L') x--;

        mx = max(mx, abs(x) + abs(y));
    } return mx;
}


int main() {
    // File input.txt contains the judge input for current test case.   
    FILE *input;
    input = fopen("input.txt", "r");

    int T;
    fscanf(input, "%d\n", &T);

    FILE *output;
    output = fopen("output.txt", "r");
    
    FILE *answer;
    answer = fopen("answer.txt", "r");


    int cnt = 0;

    while(T--) {
        int n;
        fscanf(input, "%d", &n);
        char s1[n+1], s2[n+1], s3[n+1];
        fscanf(input," %s", s1);
        fscanf(output," %s", s2);
        fscanf(answer," %s", s3);

        string S = s1, a1 = s2, a2 = s3;

        if(a1 == "Impossible" or a2 == "Impossible") {
            if(a1 != a2) cnt++;
            continue;
        }

        map<char, int> mp1, mp2;
        for(char c : S) mp1[c]++;
        for(char c : a1) mp2[c]++;


        if(mp1 != mp2 or calc(a2) < calc(a1)) printf("%d %d %d\n", 100-T, calc(a2), calc(a1)), cnt++;
    }

    cout << cnt << endl;

    return 0;
}