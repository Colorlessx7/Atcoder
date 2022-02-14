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
    ll ans = 1;
    rep(i,n){
        if(ans >= LLONG_MAX / a[i]){
            ans = -1;
            break;
        }
        ans *= a[i];
        if(ans > 1'000'000'000'000'000'000){
            ans = -1;
            break;
        }
    }
    rep(i,n){
        if(a[i] == 0){
            ans = 0;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
//a,ab,abc,abcdとかけていくよりa,b,c,dをab,cdそしてabcdとかける
//と計算中のプログラムへの処理速度的な負荷が少なく済む
