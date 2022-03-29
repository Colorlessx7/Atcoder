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
ll f(ll x,ll &d, vector<P> &t,vector<ll> &memo){
    //memoが全て埋まっている場合のベースケース
    //すでにf(x)が求められてmemo[x]が上書きされているならそれを返す
    if(0 < memo[x]){
        return memo[x];
    }
    //memoが埋まっていないものを含む再帰のベースケース
    //xがd以下(-dした数字のマスが存在しないためその時のxがジャンプの始点となる)
    //ならコストは0なので0を返す
    if(x <= d){
        return 0;
    }
    //以降f(x)を求めていない場合の処理
    //ジャンプ元(-dした数字のマス)の番号をyとする
    ll y = x - d;
    //cost:yからxにジャンプするのにかかるコスト
    //問題文の式のようにマンハッタン距離を求める
    ll cost = abs(t[x].first - t[y].first);
    cost += abs(t[x].second - t[y].second);
    //res:ジャンプの開始点x%dからxにジャンプするまでにかかるコストの合計
    //これをmemo配列のx番目に格納する
    //今のcostのままではyからxまでのコストはあるがx%dからyまでのコストが
    //計算されていないのでf(y)を計算して足し合わせる(ここで再帰する)
    ll res = cost + f(y,d,t,memo);
    //再帰が終了したらmemoする
    return memo[x] = res;
}
int main(){
    ll h, w, d;
    cin >> h >> w >> d;
    //地面の数字aに対応する座標のiをfirstにjをsecondに格納
    vector<P> t(90001);
    //入力は最初に縦を基準に横に並べていくのでi,jが逆になることに注意
    rep2(j,h){
        rep2(i,w){
            ll a;
            cin >> a;
            //地面に書いてある数字と座標の(i,j)をリンクさせる
            t[a] = make_pair(i,j);
        }
    }
    ll q;
    cin >> q;
    //ジャンプするべき目的地をxとした時そのジャンプの開始点はx%dとなる
    //f(x)をmemo[x]にメモする配列 要素は最大300^2なのでサイズは90001取る
    //memo配列はジャンプの開始点d個分が交互に混ざった累積和のような形になる
    vector<ll> memo(90001);
    //クエリ対処
    rep(i,q){
        ll l, r;
        cin >> l >> r;
        //包除原理 ジャンプの開始点は一緒(r%d==l%d)なので
        //全体f(r)から、開始点からlに辿り着くまでのコストf(l)を引けば
        //求めたいg(l,r)のコストが求められる
        ll ans = f(r,d,t,memo) - f(l,d,t,memo);
        //都度答えを出力
        cout << ans << endl;
    }
    return 0;
}
//メモ化再帰で解く問題
//g(x,y)をxからyへの経路にかかるコストとおくと
//クエリはg(l,r)=g(r%d,r)-g(l%d,l)となる
//ここでf(x)をg(x%d,x)とすると
//dが最初に与えられた条件から変わらないのでf(x)は常に不変となる
//f(x)をはじめに求めたらそれをmemo配列にメモして
//次以降の同じf(x)の処理はmemo配列から引っ張るメモ化再帰という手法を取れば良くなる
//
