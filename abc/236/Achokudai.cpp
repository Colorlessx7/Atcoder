#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    int a, b;
    cin >> S >> a >> b;
    char x;
    x = S.at(a - 1);
    S.at(a - 1) = S.at(b - 1);
    S.at(b - 1) = x;
    cout << S << endl;
}
