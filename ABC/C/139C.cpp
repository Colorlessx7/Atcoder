#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    int cnt = 0;
    int ans = 0;
    rep(i,n - 1){
        if(h[i] >= h[i + 1]){
            cnt++;
        }else {
            ans = max(ans,cnt);
            cnt = 0;
        }
        if(i == n - 2){
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
