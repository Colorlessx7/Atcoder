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
int main(){
    ll n, k;
    cin >> n >> k;
    //入力を1行で楽に書くためにiとjを逆にしている
    vector<vector<ll>> a(2,vector<ll>(n));
    rep(i,2){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    //dp[i][j]:0~iまでXとして使える数字に○をつけて行った時に
    //Aj[i]に○をつけることが可能かどうかのbooldp
    vector<vector<bool>> dp(n,vector<bool>(2));
    //dpの初期化 Xを決める上で最初から見るとして
    //A,Bの最初の一つ目はどちらも選ぶことができるのでtrue
    dp[0][0] = dp[0][1] = true;
    //最初の数字A1,B1は使えることが自明なのでその次以降の数字についてdpの遷移を処理
    //i,jは遷移先の新しい値の添字、pi,pjは遷移もとの古い値の添字をさす
    for(ll i = 1; i < n; i++){
        //jの0,1をAを見るかBを見るかとして処理
        //遷移先のA,Bについて
        rep(j,2){
            //pi:一つ前の数字を見るための添字
            ll pi = i - 1;
            //遷移もとのA,Bについて
            rep(pj,2){
                //一つ前の数字がXとして使えない場合はスルー
                if(!dp[pi][pj]){
                    continue;
                }
                //一つ前の数字(AorB)がXとして使えるとしてその数字と次にXとして
                //使おうとしている数字の絶対値の差が4を超えるならスルー
                if(abs(a[pj][pi] - a[j][i]) > k){
                    continue;
                }
                //以上の条件を突破したならその数字はXとして使えるのでtrue
                dp[i][j] = true;
            }
        }
    }
    //判定部 An,Bnのどちらか一方でもXとして使えるなら
    //Xが存在するのでYesどっちもダメならNo
    rep(j,2){
        if(dp[n-1][j]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl; 
    return 0;
}
//dpで解く問題
//dp[i][j]:0~iまでXとして使える数字に○をつけて行った時に
//Aj[i]に○をつけることが可能かどうかのbooldp
//
