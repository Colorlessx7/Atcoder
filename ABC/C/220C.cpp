#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll x;
    cin >> x;
    ll sum = 0;
    rep(i,n){
        sum += a[i];
    }
    ll ans = 0;
    ans += (x / sum) * n;
    x = x % sum;
    vector<ll> zs;
    zs.push_back(0);
    ll sum2 = 0;
    rep(i,n){
        sum2 += a[i];
        zs.push_back(sum2);
    } 
    rep(i,n + 1){
        if(x >= zs[i]){
            continue;
        }
        ans += i;
        break;
    }
    cout << ans << endl;
    return 0;
}
