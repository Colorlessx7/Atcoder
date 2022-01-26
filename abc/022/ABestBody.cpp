#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> Z(a-1);
    rep(i,a-1) {
        cin >> Z.at(i);
    }
    vector<int> X(a, d);
    for(int i = 1; i < a; i++){
        X.at(i) = X.at(i-1)+Z.at(i-1);
    }
    int cnt = 0;
    rep(i,a){
        if(X.at(i) >= b){
            if(X.at(i) <= c){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
