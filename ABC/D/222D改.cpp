#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
using mint = modint998244353;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    //dpテーブル 本来はdp[i][j]=数列のi番目にjがくる場合の数だが、
    //dp[i-1]をp配列、dp[i]をdp配列として扱って逐次swapすることでメモリを削減する
    vector<mint> dp(3001);
    //初期化 便宜上0を1として埋めておく 
    dp[0] = 1;
    rep(i,n){
        //dp[i-1]として扱うp配列の宣言
        vector<mint> p(3001);
        //swapさせることでpからdpに遷移をさせれば良くなる
        swap(dp,p);
        //累積和をとる処理
        rep(j,3000){
            p[j+1] += p[j];
        }
        //dp遷移処理部分
        rep(j,3001){
            //漸化式のΣ部分の条件式で処理するか判定
            if(a[i] <= j && j <= b[i]){
                //処理時点での数列の最後の数字がp[0]~p[j]までの足し合わせ
                //なので累積和を使うと1発で求まる
                dp[j] += p[j];
            }
        }
    }
    mint ans;
    //dpの最後の桁がi(1<=i<=3000)になる組み合わせの数がdp[i]なので
    //全てを足し合わせたものが答えになる
    rep(i,3001){
        ans += dp[i];
    }
    cout << ans.val() << endl;
    return 0;
}
//dpをしたいが状態の数がo(N^2)で遷移でo(N)となり
//最終的な計算量がo(N^3)となってN<=3000のためtleする
//漸化式はdp[i][j] = 0 (下記の条件以外)
//                = Sum[dp[i-1][k]{k<=j}] (a[i]<=j<=b[i])となる
//漸化式のSum[dp[i-1][k]{k<=j}]の部分が累積和を使って計算量を削減できる
//
//例としてa={1,1,5},b={2,4,6}としたときに
//添字   0 1 2 3 4 5 6
//累積和 1 1 1 1 1 1 1
//dp    0 1 1 0 0 0 0 (1<= j <= 2)
//累積和 0 1 2 2 2 2 2
//dp    0 1 2 2 2 0 0 (1<= j <= 4)
//累積和 0 1 3 5 7 7 7
//dp    0 0 0 0 0 7 7 (5<= j <= 6)
//という感じになる
