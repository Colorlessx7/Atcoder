#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int y;
    y = S.size();
    if (S.at(y - 1) == 'T'){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
