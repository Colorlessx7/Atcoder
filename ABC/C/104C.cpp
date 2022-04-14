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
  //D:問題の種類数、G:要求される総合スコア
  ll D, G;
  cin >> D >> G;
  //点数は必ず100の倍数になり、dpテーブルを作る上でメモリサイズの観点から
  //事前に100で割っておく
  G /= 100;
  //p:100*i点の問題が何個あるか、c:100*i点の問題を全問正解した時のボーナス点
  vector<ll> p(D+1),c(D+1);
  rep2(i,D){
    cin >> p[i] >> c[i];
    //上と同様に点数を事前に100で割っておく
    c[i] /= 100;
  }
  //最小個数部分和問題なのでdpは大きい値で初期化
  const int INF = 1001001001;
  //dp[i][j]:i点の問題まででj点得るための最小問題数
  //i=D+1:一問も見ていない0からD点の問題まで見ている状態のDまで
  //j=105501:要求される総合スコアGの上限を見積もると
  //問題の倍率Sum(1~10)*難易度毎の問題数100=5500
  //ボーナス点cの制約が100<=c<=10^6を上の処理で/=100しているので
  //cは1<=c<=10^4で問題の難易度は最大10種類から10*10^4=10^5となり
  //合計で105500がGの最大値となる
  //よってスコアは0<=Score<=105500となるため105501で宣言
  vector<vector<ll>> dp(D+1,vector<ll>(105501,INF));
  //初期化:何も問題を見ていない状態の点数は0であり
  //その時の解いた問題数は0であるためdp[0][0]=0
  dp[0][0] = 0;
  //漸化式遷移部分 配るdpとして処理
  //問題の種類についてのループ
  rep2(i,D){
    //スコアについてのループ
    rep(j,105501){
      //dp[i-1][j]がINFでない=i-1点の問題までを数問解いて
      //j点とる解き方が存在する場合処理(0問解いた場合もある)
      if(dp[i-1][j] != INF){
        //i点の問題を0問~p[i]問解いた場合の処理
        for(ll k = 0; k <= p[i]; k++){
          //k=p[i]ならボーナス点を加味する処理
          if(k == p[i]){
            //j;i-1点の問題まででとった点数
            //k:i点の問題を何問解いたか
            //i:i点の問題の得点倍率
            //c[i]:i点の問題を全て解いた時のボーナス点
            //問題数dp[i-1][j]を解いた状態でi点の問題をk問
            //とくと左辺のjに対応する点数を獲得できる
            chmin(dp[i][j+k*i+c[i]],dp[i-1][j]+k);
          }else {
            //ボーナス点を加味しない処理
            chmin(dp[i][j+k*i],dp[i-1][j]+k);
          }
        }
      }
    }
  }
  //ans:G点以上とるための最小問題数
  //minを取るのであらかじめ大きい値に
  ll ans = INF;
  //G点以上取れてればいいのでG~105500の範囲で最小の値をとる
  replr(i,G,105501){
    //D点の問題まで解いた状態(最後)で総合でi点とった時の最小問題数がdp[D][i]
    if(dp[D][i] != INF){
      ans = min(ans,dp[D][i]);
    }  
  }
  cout << ans << endl;
  return 0;
}
//dp最小個数部分和問題 dp[i][j]:i番目の問題まででj点得るための最小問題数
//chmin関数はdp変数を左右辺に両方書かないようにするため
//minを取ることで同じj点の取り方があったとしてもより少ない問題数になるよう処理できる
