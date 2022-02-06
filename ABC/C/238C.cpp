#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using mint = modint998244353;
mint sum(ll x){
    /*等差数列の和の応用,(1+x)/2が等差数列の1~xまでの平均であり
    　それに長さxをかけた場合、それは等差数列1~xまでの合計となる
    　これをACLのmodintでmodをとりmainに返す*/
    return mint(1 + x) * x / 2;
}
int main(){
    ll n;
    cin >> n;
    ll l = 1;
    mint ans;
    while(l <= n){
        ll r = l * 10;
        // (l,r)1~(n)~9,10~(n)~99,100~(n)~999,1000~(n)~2022までを分けて処理
        ll len = min(n + 1,r) - l;
        ans += sum(len);
        l *= 10; 
    }
    /*valはACLを活用しないといけないタイミングで学習 */
    cout << ans.val() << endl;
    return 0;
}
