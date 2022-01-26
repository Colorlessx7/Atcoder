#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    vector<vector<int>> Z(3, vector<int>(2));
    rep(i,3) {
        rep(j,2) {
            cin >> Z.at(i).at(j);
        }
    }
    int y = 0;
    rep(i,3){
        y += Z.at(i).at(0) * Z.at(i).at(1) / 10; 
    }
    cout << y << endl;
    return 0;
}
