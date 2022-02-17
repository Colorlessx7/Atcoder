#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        --a;
        ans += a;
    }
    cout << ans << endl;
    return 0;
}
