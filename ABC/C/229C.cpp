#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n, w;
    cin >> n >> w;
    vector<pair<ll,ll>> ab(n);
    rep(i,n){
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.rbegin(),ab.rend());
    pair<ll,ll> ans(0,w);
    int i = 0;
    while(ans.second > 0 && i < n){
        if(ans.second - ab[i].second > 0){
            ans.first += ab[i].first * ab[i].second;
            ans.second -= ab[i].second;
        }else {
            ans.first += ab[i].first * ans.second;
            ans.second = 0;
        }
        i++;
    }
    cout << ans.first << endl;
    return 0;
}
