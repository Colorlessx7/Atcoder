#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    vector<int> Z(3);
    rep(i,3) {
        cin >> Z.at(i);
    }
    bool check = 0;
    sort(Z.begin(),Z.end());
    rep(i,2){
        if(Z.at(i) != 5){
            check = 1;
            break;
        }
    }
    if(Z.at(2) != 7){
        check = 1;
    }
    if(check == 0){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

    return 0;
}
