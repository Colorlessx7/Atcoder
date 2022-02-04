#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    int diff;
    int ans = INT_MAX;
    for(int i = 0; i <= n - k; i++){
        diff = h[i+k-1] - h[i];
        ans = min(ans,diff);    
    }
    cout << ans << endl;
    return 0;
}
