#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i < N; i++)
int main(){
    int N;
    cin >> N;
    vector<int> Z(N);
    rep(i,N) {
        cin >> Z.at(i);
    }
    int y = Z.at(0);
    rep2(i,N){
        if(Z.at(i - 1) < Z.at(i)){
            y = Z.at(i);
        } else{
            break;
        }
    }
    cout << y << endl;
    return 0;
}
