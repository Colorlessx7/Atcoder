#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> ans = divisor(n);
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}
