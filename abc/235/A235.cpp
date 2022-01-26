#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string x;
    cin >> x;
    int a=0;
    rep(i,3){
        a += x.at(i) - '0';
    }
    cout << a+ a*10 + a*100 << endl;
    return 0;
}
