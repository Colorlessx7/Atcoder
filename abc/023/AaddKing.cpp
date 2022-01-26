#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string X;
    cin >> X;
    int n = X.size();
    int ans = 0;
    rep(i,n){
        ans += X.at(i) - '0';
    }
    cout << ans << endl;
    return 0;
}
