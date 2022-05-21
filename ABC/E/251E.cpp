#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  const ll INF = 1e18;
  //dp[i][j][k]:辺をi本目まで見た時の、最後の辺がjで、直前の辺がkである時の最小コスト
  //iは0~nで1本も見てない状態から全部見た状態まで
  //j,kは辺についてで0ならその辺の両端の動物に餌を買い与えない状態、1なら買い与える状態
  vector dp(n+1,vector(2,vector<ll>(2,INF)));
  //dpの初期化(辺について1本も決めてない状態のみ最小コストを0に、それ以外をINFに初期化する)
  rep(j,2){
    dp[0][j][j] = 0;
  }
  //dp遷移部分
  //i:全ての辺について処理
  rep(i,n){
    //最後の辺について購入するかしないかどちらも処理
    rep(j,2){
      //直前の辺について購入するかしないかどちらも処理
      rep(k,2){
        //now:遷移元の最小コスト
        ll now = dp[i][j][k];
        //遷移先(辺1本考慮した後)のiについての変数
        ll ni = i+1;
        //nk:次の辺について購入するかしないか
        rep(nk,2){
          //直前の辺と今の辺について両方購入しない場合全ての動物に餌が行き渡らなくなるためコンティニュー
          if(k == 0 && nk == 0){
            continue;
          }
          //辺をi+1本目まで見た時の最後の辺がjで今の辺がnkの時の最小コストが
          //遷移元の最小コストから辺の購入するかによってのコストを足したものより少ないのであれば更新
          chmin(dp[ni][j][nk],now+a[i]*nk);
        }
      }
    }
  }
  //minを取るためINFで初期化
  ll ans = INF;
  //dp[i][j][k]のjとkが一致しているものだけが答えになる可能性がある
  //(j,kは共に最後の辺について購入するかどうかを示しているため一致している必要がある)
  rep(j,2){
    chmin(ans,dp[n][j][j]);
  }
  cout << ans << endl;
  return 0;
}
//dp問題
//すべての動物に1回以上餌をあげるには、明らかに、同じ種類の行動を2回以上行う必要はない
//n匹の動物を頂点、餌をあげる買い方を餌をあげる対象を繋いだ辺として考えると
//その辺についてそれぞれo:aを使い、辺を構成する頂点を示す2匹に餌を与える,x:餌をaを使って与えない
//をつけて行った時の最小コストを求めれば良い(ただしo,xの順番はxが2連続で並ぶことはない)
//
