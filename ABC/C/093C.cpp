#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    vector<int> a(3);
    rep(i,3){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int sum = 0;
    rep(i,3){
        sum += a[i];
    }
    int ans;
    if((sum - a[2]) % 2 == 0){
        ans = (a[2] * 3 - sum) / 2; 
    }else {
        ans = ((a[2] + 1) * 3 - sum) / 2;
    }
    cout << ans << endl;
    return 0;
}
