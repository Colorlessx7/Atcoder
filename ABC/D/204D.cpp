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
    ll n;
    cin >> n;
    //dp vector<bool>のtrue,falseをbitの1,0とする
    //1つのオーブンで何個かの料理を完成させるのに必要な時間をbitの桁とする
    //bitsetでdpを取るため一番右の位が下の桁になるため
    //右1桁目が0分,左に進むにつれて1,2,3,4...というふうにbool配列と逆になる
    bitset<100001> dp;
    //dpの初期化 1つのオーブンで何も作らない場合の0分をtrueに
    dp[0] = 1;
    //全ての料理を1つのオーブンで作ったときにかかる時間(totalの略)
    ll tot = 0;
    rep(i,n){
        ll t;
        cin >> t;
        //入力された料理の完成に必要な時間をtotalにたす
        tot += t;
        //dpの遷移式
        //部分和booldpは状態遷移が上の段がtrueなら下の段もtrueにする遷移と
        //上の段がtrueなら新しく追加された要素分右にずらした下の段の位置をtrueにする遷移がある
        //これはbit演算で一つ上の段のdp配列をt回左シフトさせたものと元のもので
        //ORを取ったものと一致する
        dp |= dp << t;
    }
    //最終的な答え minをとるので必要時間の最大であるtotalをansにしておく
    ll ans = tot;
    rep(i,tot+1){
        //i分でいくつかの料理を完成させられるのなら
        if(dp[i]){
            //i:1つ目のオーブンで料理を数個作るのにかかる時間
            //tot-i:2つ目のオーブンで1つ目のオーブンで作らなかった料理を
            //全て作った時にかかる時間
            //この2つの多い方が最終的にかかる時間となる
            ans = min(ans, max(i,(tot - i)));
        }
    }
    cout << ans << endl;
    return 0;
}
//dpの部分和問題
//片方のオーブンで料理を何個か完成させることができる時間をdpで探索する
//例を8,3,7,2,5とすると料理を何個か完成させることができる時間は
//0,2,3,5,7,8,9,10,12,13,14,15,17,18,20,25に多分なる
//全体を完成させる上で必要な時間tot(例なら25)を事前に持っておいて
//この値とtotからこの値を引いたもののmaxが一番小さいものを答えとすれば良い

//dp[i][j]とするとjがいくつかの料理をj分で作りきれるか
//iが料理の数
//bit演算で更新できるのでiを省略して1次元dpとする
//
