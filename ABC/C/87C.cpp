#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n;
    cin >> n;
    vector<int> a1(n),a2(n);
    rep(i,n){
        cin >> a1[i];
    }
    rep(i,n){
        cin >> a2[i];
    }
    int ans = 0;
    rep(i,n){
        int sum = 0;
        for(int j = 0; j <= i; j++){
            sum += a1[j];
        }
        for(int j = n - 1; j >= i; j--){
            sum += a2[j];
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
