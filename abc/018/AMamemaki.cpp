#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << 1 + (a < b) + (a < c) << endl;
    cout << 1 + (b < a) + (b < c) << endl;
    cout << 1 + (c < a) + (c < b) << endl;
    return 0;
}
