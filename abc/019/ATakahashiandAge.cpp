#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    vector<int> Z(3);
    rep(i,3) {
        cin >> Z.at(i);
    }
    sort(Z.begin(), Z.end());
    cout << Z.at(1) << endl;
    return 0;
}
