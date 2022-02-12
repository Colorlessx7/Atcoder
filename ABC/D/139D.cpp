#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        ans += i;
    }
    cout << ans << endl;
    return 0;
}
