#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    int b;
    double y;
    cin >> a >> b;
    y = double(a + b) / 2;
    int y2 = y;
    double check;
    check = y - y2;
    if (check >= 0.5){
        y2++;
    }
    cout << y2 << endl;
}
