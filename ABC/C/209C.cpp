#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using mint = modint1000000007;
mint Ans(ll x){
    mint ret = 1; 
    vector<ll> c(x);
    rep(i,x){
        cin >> c[i];
    }
    sort(c.begin(),c.end());
    rep(i,x){
        ret *= c[i] - i; 
    }
    return ret;
}
int main(){
    ll n;
    cin >> n;
    mint ans = Ans(n);
    cout << ans.val() << endl;
    return 0;
}
