#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        a[i] = a[i] % 200;
    }
    map<int,int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    ll ans = 0;
    for(auto p : mp){
        if(p.second > 1){
            ans += (ll)(1 + (p.second - 1))* (p.second - 1) / 2 ;
        }
    }
    cout << ans << endl;
    return 0;
}
