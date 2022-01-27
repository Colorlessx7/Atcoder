#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x;
    if(a > b){
        x = b;
    }else {
        x = a;
    }
    cout << c / x << endl;
    return 0;
}
