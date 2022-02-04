#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(h.rbegin(),h.rend());
    ll ans = 0;
    rep(i,n - k){
        ans += h[i + k];
    }
    cout << ans << endl;
    return 0;
}
