#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    ll k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<ll> ans(n,k/n);
    sort(a.begin(),a.end());
    ll ex = k % n;
    rep(i,ex){
        ans[a[i].second]++;
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}
