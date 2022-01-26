#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int y = a / 2;
    if(a % 2 != 0){
        y++;
    }
    cout << y << endl;
    return 0;
}
