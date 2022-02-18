#include<bits/stdc++.h>
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
    int mod = 1000000007;
    int ans = 0;
    int x = 0;
    rep(i,n){
        ans = (ans + (ll)a[i] * x) % mod;//ansがllでないため怖いがc++だと暗黙の型変換で精度が高い方にキャストされる
        x = (x + a[i]) % mod;//+ - * はいつmodをとっても答えは変わらない
    }
    cout << ans << endl;
    return 0;
}

//ACL使用版の追記
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using mint = modint1000000007;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    mint ans = 0;
    mint x = 0;
    rep(i,n){
        ans += a[i] * x;
        x += a[i];
    }
    cout << ans.val() << endl;
    return 0;
}
