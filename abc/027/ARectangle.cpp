#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    vector<int> Z(3);
    rep(i,3) {
        cin >> Z.at(i);
    }
    int y = 0;
    rep(i,3){
        y = y ^ Z.at(i);
    }
    cout << y << endl;
    return 0;
}
