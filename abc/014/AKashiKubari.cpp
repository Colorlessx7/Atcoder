#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int i = 1;
    while(a > b * i){
    i++;
    }
    cout << b * i - a << endl;
    return 0;
}
