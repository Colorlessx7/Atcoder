#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  rep(i,n){
    cin >> x[i];
  }
  //key:カウンタの数字,value:ボーナスでもらえる金額
  vector<ll> b(n+1);
  //ボーナス情報の入力
  rep(i,m){
    //c:カウンタの数字,y:お金
    int c, y;
    cin >> c >> y;
    //ボーナス情報の入力
    b[c] = y;
  }
  const ll INF = LLONG_MAX;
  //dp[i][j]:i回コインを振った時の,最後のカウンタの状態がjの時のもらえるお金の最大値
  //遷移中にmaxを取っていくため物理的にありえないパターンを=INFで初期化する
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,-INF));
  //一回もコインを振っていない状態(カウント0,お金0)のパターンの初期化
  dp[0][0] = 0;
  //コインを振る回数についてのループ
  rep(i,n){
    //カウント全パターンについて処理
    rep(j,n){
      //裏の遷移
      //dp[i][j]:コインを振る前の状態
      //dp[i+1][0]:コインを振った後に裏が出てカウントが0になった時の状態
      chmax(dp[i+1][0],dp[i][j]);
      //x[i]:表報酬,b[j+1]:カウントがj+1になった時のボーナス
      //dp[i+1][j+1]:コインを振った後に表が出てカウントがj+1になった時の状態
      chmax(dp[i+1][j+1],dp[i][j]+x[i]+b[j+1]);
    }
  }
  //最大で何円もらえるか
  ll ans = 0;
  //カウンタが0~5000の状態でのもらえるお金のmaxをとる
  rep(i,n+1){
    chmax(ans,dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}
//dp解2
