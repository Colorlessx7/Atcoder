#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((double)b/a == (double)d/c){
        cout << "DRAW" << endl;
    } else if((double)b/a > (double)d/c){
        cout << "TAKAHASHI" << endl;
    } else {
        cout << "AOKI" << endl;
    }
    return 0;
}
