#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if((a+1)*b >= a*(b+1)){
        cout << (a+1)*b << endl;
    }else{
        cout << a*(b+1) << endl;
    }
    return 0;
}
