#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int a;
    cin >> a;
    int y = 0;
    rep(i,a){
        y += i + 1;
    }
    cout << y * 10000 / a << endl;
    return 0;
}
