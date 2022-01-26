#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    if (a == 100){
        cout << "Perfect" << endl;
    }else if(a >= 90){
        cout << "Great" << endl;
    }else if(a >= 60){
        cout << "Good" << endl;
    }else {
        cout << "Bad" << endl;
    }
    return 0;
}
