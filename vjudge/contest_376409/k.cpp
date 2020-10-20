#include <bits/stdc++.h>
using namespace std;
void primefactors(int n)
{
    if(n%2==0) cout << 2 << " ";
    while (n % 2 == 0){
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2){
        if(n%i==0) cout << i << " ";
        while (n % i == 0){
            n = n/i;
        }
    }
    if (n > 2)
        cout << n << " ";
}
int main()
{
    for(int i=2;i<=100000;i++)
    {
        cout<< i << ": ";
        primefactors(i);
        cout << endl;
    }
}