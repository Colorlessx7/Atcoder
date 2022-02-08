#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<ll,int>> ab(n);
    rep(i,n){
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(),ab.end());
    ll ans = 0;
    ll now = k;
    rep(i,n){
        if(ab[i].first <= now){
            now += ab[i].second;
            if(i == n - 1){
                ans = min(now,LLONG_MAX);
            }
        }else {
            ans = min(now,LLONG_MAX);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
